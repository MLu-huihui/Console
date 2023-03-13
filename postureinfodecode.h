#ifndef POSTUREINFODECODE_H
#define POSTUREINFODECODE_H

#include <QObject>
#include <qserialport.h>
#include "gcsmavlink/gcsmavlink/mavlink.h"
#include <unistd.h>
#include <qdebug.h>

class PostureInfoDecode : public QObject
{
    Q_OBJECT
public:
    explicit PostureInfoDecode(QSerialPort *serialPort, QObject *parent = nullptr);
    ~PostureInfoDecode();

    //PostureInfoDecode线程执行函数
    void Working();

    mavlink_robot_posture_info_t* postureInfo;

private:

    //串口声明
    QSerialPort *openedPort;

signals:
    void GetPostureInfo(mavlink_robot_posture_info_t* info);

};

#endif // POSTUREINFODECODE_H
