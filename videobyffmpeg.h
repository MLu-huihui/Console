#ifndef VIDEOBYFFPEG_H
#define VIDEOBYFFPEG_H

#include <QObject>
#include <QMainWindow>
#include <QDebug>
#include <QImage>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>

extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
}


class VideoByFfmpeg : public QObject
{
    Q_OBJECT
public:
    explicit VideoByFfmpeg(QString url, AVPixelFormat pix_fmt, QObject *parent = nullptr);
    ~VideoByFfmpeg();

    //run function，多线程run函数
    void Working();

    //初始化ffmpeg
    bool InitFfmpeg();

    //立刻停止视屏播放线程
    void StopVideo();

private:
    //输入数据的各种相关信息
    AVFormatContext *pAVFormatContext=nullptr;
    AVCodecContext  *pAVCodecContext=nullptr;
    AVCodec         *pAVCodec=nullptr;          //解码器信息
    AVPacket        *pAVpacket=nullptr;         //数据包
    AVFrame         *pAVFrame=nullptr;
    AVFrame         *pAVFrameRgb=nullptr;

    //处理图片像素数据，图片像素格式转化，图片拉伸等
    struct SwsContext *pSwsContext=nullptr;
    AVPixelFormat   mpix_fmt;

    int videoIndex = -1;
    int numBytes =0;            // 解码后的数据长度
    uint8_t * outbuffer=nullptr;

    QString rtspUrl;

    //互斥锁，用来快速结束该线程
    QMutex lock;
    bool isCanRun;
signals:
    //每处理完一帧图片，触发一次该信号
    void GetOneFrame(QImage image);
};

#endif // VIDEOBYFFPEG_H
