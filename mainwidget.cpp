#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <qicon.h>
#include <qpixmap.h>
#include <qrect.h>
#include <qdebug.h>
#include "myvideowidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    qDebug() << __FILE__ <<__LINE__;
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

    //点击连接机器人按钮，进行机器人连接
    connect(ui->connectRobotBut, &QPushButton::clicked, this, &MainWidget::SetMainWidget);
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
}

MainWidget::~MainWidget()
{
    delete ui;
}

