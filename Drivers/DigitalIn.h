#pragma once

#include "Global.h"

#include <QString>
#include <QDebug>

#include <Hal/gpio.h>


class QUTIPICPPSHARED_EXPORT DigitalIn
{

public:
    DigitalIn();

    QString read()
    {
        qDebug() << gpio_init();

        return "Read method ran";
    }
};

