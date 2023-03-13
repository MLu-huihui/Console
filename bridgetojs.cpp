#include "bridgetojs.h"

BridgeToJs::BridgeToJs(QObject *parent) : QObject(parent)
{

}

void BridgeToJs::GetAirPoint(QVariant count, QVariant lngArry, QVariant latArry)
{
    double lngInfo[18] = {};
    double latInfo[18] = {};
    QVariantList lngList = lngArry.toList();
    QVariantList latList = latArry.toList();
    int pointCount = count.toInt();
    for(int i = 0; i < pointCount; i++)
    {
        lngInfo[i] = lngList[i].toDouble();
        latInfo[i] = latList[i].toDouble();
    }
    qDebug()<<lngInfo[0];
    qDebug()<<latInfo[0];
}
