#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <qicon.h>
#include <qpixmap.h>
#include <qrect.h>
#include <qdebug.h>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    qDebug() << __FILE__ <<__LINE__;
    //设置视屏播放Label鼠标穿透
    ui->videoLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
    //ui->homeButBox->setAttribute(Qt::WA_TransparentForMouseEvents);
    //隐藏关闭视屏按钮
    ui->closeVideoBut->hide();
    //设置HOME图标
    ui->homeButBox->hide();
    QPixmap pix;
    pix.load(":/PIX/ICON/resource/home.png");
    ui->home_Button->setFixedSize(pix.size());
    ui->home_Button->setIcon(QIcon(pix));
    ui->home_Button->setIconSize(pix.size());
    //HOME键点击效果
    connect(ui->home_Button,&QToolButton::clicked, this,[=](){
        if(ui->home_Button->isChecked())
        {
            ui->homeButBox->show();
        }else
        {
            ui->homeButBox->hide();
        }
    });

    //隐藏各模式界面
    ui->groundInformation->hide();
    ui->flyInformation->hide();
    ui->flyModeFunBox->hide();

    //设置选择连接目标的图标
    pix.load(":/PIX/ICON/resource/robot.jpg");
    QPixmap selectPix = pix.scaled(260,320,Qt::KeepAspectRatio);
    ui->switchPixLabel->setFixedSize(selectPix.size());
    ui->switchPixLabel->setPixmap(selectPix);

    //点击参数设置按钮
    connect(ui->settingBut,&QPushButton::clicked,this,[&](){
        this->setting_Widget = new SettingWidget;
        setting_Widget->setAttribute(Qt::WA_DeleteOnClose);
        setting_Widget->show();
        //设置参数设置界面弹出位置
        QRect rect = this->geometry();
        setting_Widget->move(rect.x() + (rect.width() - setting_Widget->width())/2, rect.y()+(rect.height() - setting_Widget->height())/2);

        //参数设置界面发出信号，主界面作出响应
        connect(setting_Widget,&SettingWidget::ApplySetting, this, &MainWidget::ApplySetting);
    });

    //搜索可连接的机器人
    connect(ui->searchRobotBut,&QPushButton::clicked,this,[=](){
        this->ui->searchRobotBut->setEnabled(false);
        ui->connectRobotBut->setEnabled(true);
    });

    videoJob = nullptr;
    joystickJob = nullptr;
    //点击连接机器人按钮，进行机器人连接
    connect(ui->connectRobotBut, &QPushButton::clicked, this, &MainWidget::SetMainWidget);

    //点击视屏播放按钮，实现视屏播放
    connect(ui->videoBut, &QPushButton::clicked, this, [=](){
        ui->videoBut->setEnabled(false);
        ui->closeVideoBut->show();
        ui->videoLabel->show();

        //此处后续应该加上从参数设置文件中读取视屏地址
        videoThread = new QThread;
        videoJob = new VideoByFfmpeg("rtsp://192.168.144.25:8554/main.264",AV_PIX_FMT_RGBA);
        videoJob->moveToThread(videoThread);
        connect(this, &MainWidget::StartPlay, videoJob, &VideoByFfmpeg::Working);
        connect(videoJob, &VideoByFfmpeg::GetOneFrame, this, &MainWidget::PlayVideo,Qt::QueuedConnection);

        if(videoJob->InitFfmpeg())
        {
            emit StartPlay();
            videoThread->start();
            qDebug() << "视屏线程开始工作";
        }
    });

    //点击视屏关闭按钮，关闭视屏
    connect(ui->closeVideoBut, &QPushButton::clicked, this, [=](){
        qDebug() << "开始关闭视屏";
        ui->closeVideoBut->hide();
        ui->videoBut->setEnabled(true);
        ui->videoLabel->hide();

        videoJob->StopVideo();
        videoThread->quit();
        videoThread->wait();
        videoThread->deleteLater();

        videoJob->deleteLater();
        qDebug() << "关闭视屏成功";
        videoJob = nullptr;
    });
}

void MainWidget::ApplySetting()
{
    setting_Widget->GetLocation();

}


//连接设备后界面设置槽函数
void MainWidget::SetMainWidget()
{
    QPixmap pix;
    //绘制地面模式仪表盘并且隐藏
    pix.load(":/PIX/ICON/resource/groundMap.png");
    QPixmap groundPix = pix.scaled(ui->groundMap->size(),Qt::KeepAspectRatio);
    ui->groundMap->setPixmap(groundPix);
    ui->groundInformation->hide();

    //绘制飞行仪表盘并且隐藏
    pix.load(":/PIX/ICON/resource/flyMap.png");
    QPixmap flyPix = pix.scaled(ui->flyMap->size(),Qt::KeepAspectRatio);
    ui->flyMap->setPixmap(flyPix);
    ui->flyInformation->hide();
    //绘制一键操作按键并且隐藏
    pix.load(":/PIX/ICON/resource/huijia.png");
    ui->fly_Home->setIcon(QIcon(pix));
    ui->fly_Home->setIconSize(pix.size());
    pix.load(":/PIX/ICON/resource/qifei.png");
    ui->fly_qifei->setIcon(QIcon(pix));
    ui->fly_qifei->setIconSize(pix.size());
    pix.load(":/PIX/ICON/resource/jiangliuo.png");
    ui->fly_jiangluo->setIcon(QIcon(pix));
    ui->fly_jiangluo->setIconSize(pix.size());
    pix.load(":/PIX/ICON/resource/wurenji.png");
    ui->fly_xuanting->setIcon(QIcon(pix));
    ui->fly_xuanting->setIconSize(pix.size());
    ui->flyModeFunBox->hide();

    //删除搜索与连接设备的控件
    delete ui->searchRobotBut;
    delete ui->connectRobotBut;
    delete ui->choseWidget;
    delete ui->switchPixLabel;
    ui->groundInformation->show();
    ui->offRoadModeBut->setEnabled(true);
    ui->flyModeBut->setEnabled(true);
    ui->videoBut->setEnabled(true);

    //点击飞行某所按钮，切换到飞行模式
    connect(ui->flyModeBut,&QPushButton::clicked,this,[=](){
        ui->groundInformation->hide();
        ui->groundModeBut->setEnabled(true);
        ui->offRoadModeBut->setEnabled(true);
        ui->flyInformation->show();
        ui->flyModeFunBox->show();
        ui->flyModeBut->setEnabled(false);

    });
    //切换到平地模式与越野模式
    connect(ui->groundModeBut,&QPushButton::clicked,this,[=](){
        ui->groundInformation->show();
        ui->groundModeBut->setEnabled(false);
        ui->offRoadModeBut->setEnabled(true);
        ui->flyInformation->hide();
        ui->flyModeFunBox->hide();
        ui->flyModeBut->setEnabled(true);
    });
    connect(ui->offRoadModeBut,&QPushButton::clicked,this,[=](){
        ui->groundInformation->show();
        ui->groundModeBut->setEnabled(true);
        ui->offRoadModeBut->setEnabled(false);
        ui->flyInformation->hide();
        ui->flyModeFunBox->hide();
        ui->flyModeBut->setEnabled(true);
    });

    //实现Joystick线程的工作
    joystickThread = new QThread;
    joystickJob = new JoystickThread;
    joystickJob->moveToThread(joystickThread);
    connect(this, &MainWidget::StartJS, joystickJob, &JoystickThread::Working);
    connect(joystickJob, &JoystickThread::GetJSValue, this, &MainWidget::SentCtrlInfo, Qt::QueuedConnection);
    qDebug()<<"准备初始化Joystick";
    if(joystickJob->JoystickInit())
    {
        emit StartJS();
        joystickThread->start();
        qDebug() << "开始接受JS数据";
    }
}

void MainWidget::PlayVideo(QImage image)
{
    QImage videoImage = image.scaled(ui->videoLabel->width(), ui->videoLabel->height());
    ui->videoLabel->setScaledContents(true);
    ui->videoLabel->setPixmap(QPixmap::fromImage(videoImage));
}

void MainWidget::SentCtrlInfo(JoyStickVal js)
{
    ui->LXValue->setText(QString::number(js.leftX));
    ui->LYValue->setText(QString::number(js.leftY));
    ui->RXValue->setText(QString::number(js.rightX));
    ui->RYValue->setText(QString::number(js.rightY));
    ui->LS1Value->setText(QString::number(js.switchL1));
    ui->LS2Value->setText(QString::number(js.switchL2));
    ui->RSValue->setText(QString::number(js.switchR));
}

MainWidget::~MainWidget()
{
    if(videoJob)
    {
        videoJob->StopVideo();
        videoThread->quit();
        videoThread->wait();
        videoThread->deleteLater();
        qDebug()<<"退出视屏播放线程";
        videoJob->deleteLater();
    }
    if(joystickJob)
    {
        joystickJob->StopJS();
        joystickThread->quit();
        joystickThread->wait();
        joystickThread->deleteLater();
        qDebug()<<"退出JS线程";
        joystickJob->deleteLater();
    }
    delete ui;
}

