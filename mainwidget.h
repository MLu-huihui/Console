#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <settingwidget.h>
#include <qdebug.h>
#include <qthread.h>
#include "videobyffmpeg.h"
#include "myvideowidget.h"

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
    QThread *videoThread = nullptr;
    VideoByFfmpeg *videoJob = nullptr;

public slots:
    void ApplySetting();

    //点击连接设备后，对主界面进行相应显示
    void SetMainWidget();
    //接受到解析后的视屏进行播放
    void PlayVideo(QImage image);
signals:
    //点击视屏播放按钮后，发出播放视屏信号
    void StartPlay();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
