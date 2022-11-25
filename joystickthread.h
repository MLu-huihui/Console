#ifndef JOYSTICKTHREAD_H
#define JOYSTICKTHREAD_H

#include <QObject>
#include "mystruct.h"
#include <linux/input.h>
#include <stdio.h>
#include <fcntl.h>
#include <qdebug.h>
#include <linux/joystick.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <qthread.h>
#include "consoletest/consoletest/mavlink.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMutex>
#include <QMutexLocker>

#define JS_AXIS_LX      0x03    /* 左摇杆X轴 */
#define JS_AXIS_LY      0x00    /* 左摇杆Y轴 */
#define JS_AXIS_RX      0x01    /* 右摇杆X轴 */
#define JS_AXIS_RY      0x02    /* 右摇杆Y轴 */
#define JS_AXIS_SL1     0x04
#define JS_AXIS_SL2     0x06
#define JS_AXIS_SR      0x05    /* 方向键X轴 */

#define GROUND_MODE     0
#define OFFROAD_MODE    1
#define FLY_MODE        2
#define AUTO_MODE       3



class JoystickThread : public QObject
{
    Q_OBJECT
public:
    explicit JoystickThread(QObject *parent = nullptr);
    ~JoystickThread();

    //joystick初始化函数
    bool JoystickInit();

    //joystick线程执行函数
    void Working();

    //立刻停止遥控器信号线程
    void StopJS();

private:
    JoyStickVal* js_val;
    //文件描述符
    int js_fd;

    //串口声明
    QSerialPort *serialPort;
    //mavlink消息包
    mavlink_message_t msg;

    //互斥锁，用来快速结束线程
    QMutex lock;
    bool isCanRun;

signals:
    void GetJSValue(JoyStickVal js);

};

#endif // JOYSTICKTHREAD_H
