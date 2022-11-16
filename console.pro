QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    joystickthread.cpp \
    main.cpp \
    mainwidget.cpp \
    myvideowidget.cpp \
    settingwidget.cpp \
    videobyffmpeg.cpp

HEADERS += \
    joystickthread.h \
    mainwidget.h \
    mystruct.h \
    myvideowidget.h \
    settingwidget.h \
    videobyffmpeg.h

FORMS += \
    mainwidget.ui \
    settingwidget.ui


RESOURCES += \
    rcs.qrc

LIBS += -L/usr/local/lib -lavformat -lavcodec -lavutil -lswresample -lswscale -lz

