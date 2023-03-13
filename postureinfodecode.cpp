#include "postureinfodecode.h"

PostureInfoDecode::PostureInfoDecode(QSerialPort *serialPort, QObject *parent) : QObject(parent)
{
    openedPort = serialPort;
}

PostureInfoDecode::~PostureInfoDecode()
{

}

void PostureInfoDecode::Working()
{
    postureInfo = (mavlink_robot_posture_info_t*)malloc(sizeof(mavlink_robot_posture_info_t));
    memset(postureInfo, 0, sizeof(mavlink_robot_posture_info_t));
    uint8_t getBuf[40] = {0};
    uint8_t chan = MAVLINK_COMM_0;
    mavlink_message_t rmsg;
    mavlink_status_t status;
    while(1)
    {
//        qDebug()<<"开始接收姿态信息";
        int len = openedPort->readLine((char*)getBuf, 41);
        //uint8_t* changeBuf = (unsigned char*)getBuf;
        if(len < 0)
        {
            usleep(1000);
            continue;
        }
        for(int i =0; i < len; i++)
        {
            if(mavlink_parse_char(chan, (uint8_t)getBuf[i],&rmsg, &status) == 1)
            {
                switch (rmsg.msgid)
                {
                case MAVLINK_MSG_ID_ROBOT_POSTURE_INFO:
                    mavlink_msg_robot_posture_info_decode(&rmsg, postureInfo);
                    emit GetPostureInfo(postureInfo);
                    break;
                default:
                    break;
                }
            }
        }
    }

}
