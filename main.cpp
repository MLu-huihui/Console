#include "mainwidget.h"
#include "mystruct.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<JoyStickVal>("JoyStickVal");
    qRegisterMetaType<mavlink_robot_posture_info_t>("mavlink_robot_posture_info_t");
    MainWidget w;
    w.show();
    return a.exec();
}
