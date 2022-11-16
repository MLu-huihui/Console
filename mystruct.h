#ifndef MYSTRUCT_H
#define MYSTRUCT_H

#include <QMetaType>

typedef struct JoyStickVal
{
    int time;

    int leftX;
    int leftY;
    int rightX;
    int rightY;

    int switchL1;
    int switchL2;
    int switchR;
}JoyStickVal;

Q_DECLARE_METATYPE(JoyStickVal)

#endif // MYSTRUCT_H
