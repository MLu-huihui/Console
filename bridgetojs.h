#ifndef BRIDGETOJS_H
#define BRIDGETOJS_H

#include <QObject>
#include <qdebug.h>
#include <qjsonarray.h>

class BridgeToJs : public QObject
{
    Q_OBJECT
public:
    explicit BridgeToJs(QObject *parent = nullptr);

public slots:
    void GetAirPoint(QVariant count, QVariant lngArry, QVariant latArry);

signals:

};

#endif // BRIDGETOJS_H
