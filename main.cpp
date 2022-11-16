#include "mainwidget.h"
#include "mystruct.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<JoyStickVal>("JoyStickVal");
    MainWidget w;
    w.show();
    return a.exec();
}
