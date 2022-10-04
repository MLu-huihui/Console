#ifndef MYVIDEOWIDGET_H
#define MYVIDEOWIDGET_H

#include <QWidget>
#include <qmediaplayer.h>
#include <qvideowidget.h>
#include <qmediaplaylist.h>
#include <qfile.h>

class MyVideoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyVideoWidget(QWidget *parent = nullptr);

signals:

};

#endif // MYVIDEOWIDGET_H
