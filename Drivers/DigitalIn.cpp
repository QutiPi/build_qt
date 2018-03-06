#include "DigitalIn.h"
#include <QDebug>

DigitalIn::DigitalIn()
{
    qDebug() << "DigitalIn class created" << gpio_init();
}
