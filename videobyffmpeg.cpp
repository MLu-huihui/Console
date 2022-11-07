#include "videobyffmpeg.h"

VideoByFfmpeg::VideoByFfmpeg(QString url, AVPixelFormat pix_fmt, QObject *parent) : QObject(parent)
{
    rtspUrl = url;
    mpix_fmt = pix_fmt;
}

VideoByFfmpeg::~VideoByFfmpeg()
{
    if(outbuffer) av_free(outbuffer);
    if(pSwsContext) sws_freeContext(pSwsContext);
    if(pAVFrameRgb) av_frame_free(&pAVFrameRgb);
    if(pAVFrame) av_frame_free(&pAVFrame);
    if(pAVpacket) av_packet_free(&pAVpacket);
    if(pAVCodecContext) avcodec_close(pAVCodecContext);
    if(pAVFormatContext) avformat_free_context(pAVFormatContext);

}

void VideoByFfmpeg::Working()
{
    isCanRun = true;
    qDebug() << "start Working()";
    while(av_read_frame(pAVFormatContext,pAVpacket)>=0) //av_read_frame()读取一帧数据
    {
        {
            QMutexLocker locker(&lock);
            if(!isCanRun)
                break;
        }
        if(pAVpacket->stream_index==videoIndex)
        {
            if(avcodec_send_packet(pAVCodecContext, pAVpacket)) //将数据包放入解码器
            {
                qDebug() << "Failed to avcodec_send_packet(pAVCodecContext, pAVPacket)";
                break;
            }
            while(!avcodec_receive_frame(pAVCodecContext, pAVFrame))//获取解码后的数据到AVFrame中，因为解码后的数据可能不止一包，所以使用while判断
            {
                sws_scale(pSwsContext,                              //上面使用sws_getContext得到的结构体
                          pAVFrame->data, //解码后的数据
                          pAVFrame->linesize,                      //每个通道的行字节数,linesize和width不同。
                          0,                                        //起始位置
                          pAVCodecContext->height,                         //处理行数
                          pAVFrameRgb->data,                       //目的buffer
                          pAVFrameRgb->linesize
                          );
                QImage image(  outbuffer,
                               pAVCodecContext->width,
                               pAVCodecContext->height,
                               pAVFrameRgb->linesize[0],
                        QImage::Format_RGBA8888);

                //emit DrawImg(img_queue.dequeue(),temp);  //实际项目中应该使用队列控制显示速度，temp是画框的位置，
                emit GetOneFrame(image);
            }
        }
        av_free_packet(pAVpacket);
    }
}

bool VideoByFfmpeg::InitFfmpeg()
{
    avformat_network_init();
    av_register_all();

    int ret=0;
    pAVFormatContext = avformat_alloc_context();//分配全局上下文空间
    pAVpacket = av_packet_alloc();              //分配数据包空间
    pAVFrame  = av_frame_alloc();               //分配单帧空间
    pAVFrameRgb  = av_frame_alloc();           //分配rgb单帧空间
    if(!pAVFormatContext || !pAVpacket || !pAVFrame || !pAVFrameRgb)
    {
        qDebug()<< "init_mdecode failed";
        return false;
    }
    AVDictionary *optionsDict = NULL;
    av_dict_set(&optionsDict, "buffer_size", "1024000", 0); //设置缓存大小，1080p可将值调大
    av_dict_set(&optionsDict, "rtsp_transport", "udp", 0); //以udp方式打开，如果以tcp方式打开将udp替换为tcp
    av_dict_set(&optionsDict, "stimeout", "20000000", 0); //设置超时断开连接时间，单位微秒
    av_dict_set(&optionsDict, "max_delay", "30000000", 0);

    ret = avformat_open_input(&pAVFormatContext, rtspUrl.toUtf8().data(), 0, 0);

    if(ret)
    {
        qDebug() << "Failed to avformat_open_input(&pAVFormatContext, rtspUrl.toUtf8().data(), 0, 0)";
        return false;
    }
    /*
     * 探测流媒体信息。
    */
    ret = avformat_find_stream_info(pAVFormatContext, 0);
    if(ret < 0)
    {
        qDebug() << "Failed to avformat_find_stream_info(pAVCodecContext, 0)";
        return false;
    }

    av_dump_format(pAVFormatContext, 0, rtspUrl.toUtf8().data(), 0);//打印文件中包含的格式信息

    for(int index = 0; index < pAVFormatContext->nb_streams; index++) //遍历寻找视频流
    {
        pAVCodecContext = pAVFormatContext->streams[index]->codec;
        if(pAVCodecContext->codec_type==AVMEDIA_TYPE_VIDEO)
        {
            videoIndex = index;//此处只找视频流,不找音频和其他
            break;
        }
    }
    if(videoIndex == -1 || !pAVCodecContext)
    {
        qDebug() << "Failed to find video stream";
        return false;
    }

    /*
    查找解码器并打开。
    */
    pAVCodec = avcodec_find_decoder(pAVCodecContext->codec_id);
    if(!pAVCodec)
    {
        qDebug() << "Fialed to avcodec_find_decoder(pAVCodecContext->codec_id):"<< pAVCodecContext->codec_id;
        return false;
    }
    QString url_type=rtspUrl.mid(0,4);

    if(url_type=="rtsp")
    {
        if(avcodec_open2(pAVCodecContext, pAVCodec, &optionsDict))
        {
            qDebug() <<"Failed to avcodec_open2(pAVCodecContext, pAVCodec, pAVDictionary)";
            return false;
        }
    }
    else
    {
        if(avcodec_open2(pAVCodecContext, pAVCodec, NULL))
        {
            qDebug() <<"Failed to avcodec_open2(pAVCodecContext, pAVCodec, pAVDictionary)";
            return false;
        }
    }
    qDebug()<<"video W x H:"<< pAVCodecContext->width << "x" << pAVCodecContext->height<<pAVCodecContext->pix_fmt;
    numBytes = avpicture_get_size(mpix_fmt,pAVCodecContext->width,pAVCodecContext->height);       //计算转换后的内存大小
    outbuffer=(uchar*)av_malloc(numBytes);//申请转换后图片存放的内存

    /*
    * int avpicture_fill(AVPicture *picture, const uint8_t *ptr, enum AVPixelFormat pix_fmt, int width, int height)
    * 上面的pAVFrameRgba只是malloc了一段结构体内存，结构体中的数据部分是没有分配的，使用此函数将pAVFrameRgba的data和outbuffer关联起来
    * pFrameRGB里面使用的是outbuffer所指向的内存空间.
    * 此函数在ffmpeg4.2后变为av_image_fill_arrays;
    * 我理解的是这个函数主要是给buffer添加pix_fmt width height linesize等属性.
    */
    avpicture_fill((AVPicture *)pAVFrameRgb,outbuffer,mpix_fmt,pAVCodecContext->width,pAVCodecContext->height);

    /*
    * sws_getContext函数
    * 相当于初始化转换函数，当后面使用sws_scale执行转换的时候不在写入格式等信息
    */

    {
        AVPixelFormat pixFormat;
        switch (pAVCodecContext->pix_fmt) {
        case AV_PIX_FMT_YUVJ420P :
            pixFormat = AV_PIX_FMT_YUV420P;
            break;
        case AV_PIX_FMT_YUVJ422P  :
            pixFormat = AV_PIX_FMT_YUV422P;
            break;
        case AV_PIX_FMT_YUVJ444P   :
            pixFormat = AV_PIX_FMT_YUV444P;
            break;
        case AV_PIX_FMT_YUVJ440P :
            pixFormat = AV_PIX_FMT_YUV440P;
            break;
        default:
            pixFormat = pAVCodecContext->pix_fmt;
            break;
        }
        qDebug() << "开始修改pix_fmt";
        pAVCodecContext->pix_fmt = pixFormat;
      }
    qDebug() <<"运行sws_getContext";
    pSwsContext = sws_getContext(pAVCodecContext->width,pAVCodecContext->height,pAVCodecContext->pix_fmt,//转换前的长、宽、像素格式
                                 pAVCodecContext->width,pAVCodecContext->height,mpix_fmt,//转换后的长、宽、像素格式
                                 SWS_BICUBIC,                                                      //转换方法  libswscale/swscale.h
                                 0,0,0                                                                   //其他参数默认为空
                                 );
    qDebug() << "结束运行sws_getContext";
    return true;
}

void VideoByFfmpeg::StopVideo()
{
    qDebug() << "立刻打断视屏播放线程";

    QMutexLocker locker(&lock);
    isCanRun = false;
}
