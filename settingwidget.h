#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <qpushbutton.h>

namespace Ui {
class SettingWidget;
}

class SettingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWidget(QWidget *parent = nullptr);
    ~SettingWidget();

    //接口函数，提供文本信息
    int GetLocation();

signals:
    void ApplySetting();


private:
    Ui::SettingWidget *ui;
};

#endif // SETTINGWIDGET_H
