#include "joystickthread.h"

JoystickThread::JoystickThread(QObject *parent) : QObject(parent)
{

}

JoystickThread::~JoystickThread()
{
    if(js_fd > 0)
    {
        close(js_fd);
    }
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
    return true;
}

void JoystickThread::Working()
{
    int len, type, number, value;
    struct js_event js;
    while(1)
    {
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
        emit GetJSValue(*js_val);
    }
}
