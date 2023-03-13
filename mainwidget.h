#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <settingwidget.h>
#include <qdebug.h>
#include <qthread.h>
#include "videobyffmpeg.h"
#include "myvideowidget.h"
#include "joystickthread.h"
#include "postureinfodecode.h"
#include <qstring.h>
#include <qserialport.h>
#include "gcsmavlink/gcsmavlink/mavlink.h"
#include <QtWebEngineWidgets/QWebEngineView>
#include "bridgetojs.h"
#include <QWebChannel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:

    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    //声明一个参数设置界面
    SettingWidget *setting_Widget;
    //声明视频线程
    QThread* videoThread = nullptr;
    VideoByFfmpeg *videoJob = nullptr;
    //声明joystick线程
    QThread* joystickThread = nullptr;
    JoystickThread *joystickJob = nullptr;
    //声明机器人姿态信号接收、解析线程
    QThread* postureThread = nullptr;
    PostureInfoDecode* postureJOb = nullptr;

    QWebEngineView *map;
    QWebChannel *channel;
    BridgeToJs *myBridgeToJs;

    //控制台与地面端通讯串口声明
    QSerialPort *serialPort;

public slots:
    void ApplySetting();

    //点击连接设备后，对主界面进行相应显示
    void SetMainWidget();
    //接受到解析后的视屏进行播放
    void PlayVideo(QImage image);
    //接受JS信号后进行处理
    void SentCtrlInfo(JoyStickVal js);
    //接收并解析姿态信息后在仪表盘上显示
    void PanelUpdate(mavlink_robot_posture_info_t* info);

signals:
    //点击视屏播放按钮后，发出播放视屏信号
    void StartPlay();
    //开始接受joystick信号
    void StartJS();
    //开始接收并解析posture信号
    void StartPoseture();

private:
    Ui::MainWidget *ui;

};
#endif // MAINWIDGET_H
