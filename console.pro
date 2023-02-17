QT       += core gui svg multimedia multimediawidgets serialport

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
    LayoutSquare.cpp \
    Pfd.cpp \
    WidgetPFD.cpp \
    joystickthread.cpp \
    main.cpp \
    mainwidget.cpp \
    myvideowidget.cpp \
    postureinfodecode.cpp \
    settingwidget.cpp \
    videobyffmpeg.cpp

HEADERS += \
    LayoutSquare.hpp \
    Pfd.hpp \
    WidgetPFD.hpp \
    gcsmavlink/checksum.h \
    gcsmavlink/gcsmavlink/gcsmavlink.h \
    gcsmavlink/gcsmavlink/mavlink.h \
    gcsmavlink/gcsmavlink/mavlink_msg_air_point_info.h \
    gcsmavlink/gcsmavlink/mavlink_msg_fly_quick_ctrl.h \
    gcsmavlink/gcsmavlink/mavlink_msg_js_crtl_info.h \
    gcsmavlink/gcsmavlink/mavlink_msg_robot_posture_info.h \
    gcsmavlink/gcsmavlink/testsuite.h \
    gcsmavlink/gcsmavlink/version.h \
    gcsmavlink/mavlink_conversions.h \
    gcsmavlink/mavlink_helpers.h \
    gcsmavlink/mavlink_types.h \
    gcsmavlink/protocol.h \
    joystickthread.h \
    mainwidget.h \
    mystruct.h \
    myvideowidget.h \
    postureinfodecode.h \
    settingwidget.h \
    videobyffmpeg.h

FORMS += \
    WidgetPFD.ui \
    mainwidget.ui \
    settingwidget.ui


RESOURCES += \
    qfi.qrc \
    rcs.qrc

LIBS += -L/usr/local/lib -lavformat -lavcodec -lavutil -lswresample -lswscale -lz

