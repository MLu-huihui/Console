#include "joystickthread.h"

JoystickThread::JoystickThread(QSerialPort *serialPort, QObject *parent) : QObject(parent)
{
    openedPort = serialPort;
}

JoystickThread::~JoystickThread()
{
    if(js_fd > 0)
    {
        close(js_fd);
    }
    free(js_val);
    js_val = nullptr;
}

bool JoystickThread::JoystickInit()
{

    js_val = (JoyStickVal*)malloc(sizeof(JoyStickVal));
    memset(js_val, 0, sizeof(JoyStickVal));

    js_fd = open("/dev/input/js0", O_RDONLY);
    if(js_fd < 0)
    {
        qDebug() << "打开JS设备文件失败";
        return false;
    }
    qDebug() << "打开JS设备文件成功";

//    //查询可用串口
//    QList<QSerialPortInfo> serialPortInfo = QSerialPortInfo::availablePorts();
//    foreach (const QSerialPortInfo &info, serialPortInfo) {
//        qDebug()<<"serialPortName:"<<info.portName();
//    }
//    //打开串口并设置
//    serialPort = new QSerialPort();
//    serialPort->setPortName(serialPortInfo[0].portName());
//    if(serialPort->isOpen())
//    {
//        serialPort->clear();
//        serialPort->close();
//    }
//    if(!serialPort->open(QIODevice::ReadWrite))
//    {
//        qDebug()<<serialPort->portName()<<"打开失败";
//        return false;
//    }
//    serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);//设置波特率和读写方向
//    serialPort->setDataBits(QSerialPort::Data8);		//数据位为8位
//    serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
//    serialPort->setParity(QSerialPort::NoParity);	//无校验位
//    serialPort->setStopBits(QSerialPort::OneStop); //一位停止位

    return true;
}

void JoystickThread::Working()
{
    isCanRun = true;
    int len, type, number, value;
    struct js_event js;
    while(1)
    {
        {
            QMutexLocker locker(&lock);
            if(!isCanRun)
                break;
        }
        len = read(js_fd, &js, sizeof(js_event));
        if(len < 0)
        {
            qDebug()<<"读取JS0设备文件出错";
            usleep(1000);
            continue;
        }
        else
        {
            type = js.type;
            number = js.number;
            value = js.value;

            js_val->time = js.time;
            if(type == JS_EVENT_AXIS)
            {
                //根据JS中的number选择是哪个轴
                switch (number)
                {
                case JS_AXIS_LX:
                    js_val->leftX = value;
                    break;
                case JS_AXIS_LY:
                    js_val->leftY = value;
                    break;
                case JS_AXIS_RX:
                    js_val->rightX = value;
                    break;
                case JS_AXIS_RY:
                    js_val->rightY = value;
                    break;
                case JS_AXIS_SL1:
                    js_val->switchL1 = value;
                    break;
                case JS_AXIS_SL2:
                    js_val->switchL2 = value;
                    break;
                case JS_AXIS_SR:
                    js_val->switchR = value;
                    break;
                default:
                    break;
                }
            }
        }

        uint8_t mode = 0;
        if(js_val->switchL2 <= 0)
        {
            if(js_val->switchL1 < 0)
            {
                mode = GROUND_MODE;
            }
            else
            {
                mode = OFFROAD_MODE;
            }
        }
        else
        {
            if(js_val->switchR < 0)
            {
                mode = FLY_MODE;
            }
            else
            {
                mode = AUTO_MODE;
            }
        }

        int len = mavlink_msg_js_crtl_info_pack(1, 1, &msg, (int16_t)js_val->leftX, (int16_t)js_val->leftY, (int16_t)js_val->rightX, (int16_t)js_val->rightY, mode);
        uint8_t* buf = new uint8_t[len];
        len = mavlink_msg_to_send_buffer(buf, &msg);
        QByteArray sendBuf = QByteArray::fromRawData((char *)buf, len);;
        openedPort->write(sendBuf);
        //qDebug()<<sentlen;
        //qDebug()<<"buf:"<<sendBuf.toHex();
        //尝试进行解析
//        mavlink_status_t status;
//        mavlink_message_t rmsg;
//        uint8_t chan = MAVLINK_COMM_0;
//        uint8_t *getbuf = (unsigned char *)sendBuf.data();
//        for (int i = 0; i <len; i++)
//        {
//            if (mavlink_parse_char(chan, getbuf[i], &rmsg, &status) == 1)
//            {
//                switch (rmsg.msgid)
//                {
//                case MAVLINK_MSG_ID_JS_CRTL_INFO:
//                    mavlink_js_crtl_info_t heartbeat;
//                    mavlink_msg_js_crtl_info_decode(&rmsg, &heartbeat);
//                    qDebug()<<"leftX:"<<heartbeat.leftX<<". leftY:"<<heartbeat.leftY<<"rightX:"<<heartbeat.rightX<<". rightY:"<<heartbeat.rightY<<". mode:"<<heartbeat.mode;
//                    break;
//                default:
//                    break;
//                }
//            }
//        }

//        delete[] buf;
        emit GetJSValue(*js_val);
    }
}

void JoystickThread::StopJS()
{
    qDebug() << "立刻打断JS线程";

    QMutexLocker locker(&lock);
    isCanRun = false;
}
