#include "settingwidget.h"
#include "ui_settingwidget.h"

SettingWidget::SettingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWidget)
{
    ui->setupUi(this);
    //设置参数设置界面阻塞
    setWindowModality(Qt::ApplicationModal);

    //点击应用触发信号
    connect(ui->applyBut,&QPushButton::clicked,this,[=](){
        emit ApplySetting();
    });
}

int SettingWidget::GetLocation()
{
    return ui->videoLocation->text().toInt();
}

SettingWidget::~SettingWidget()
{
    delete ui;
}
