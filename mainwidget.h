#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <settingwidget.h>
#include <qdebug.h>

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

public slots:
    void ApplySetting();

    //点击连接设备后，对主界面进行相应显示
    void SetMainWidget();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
