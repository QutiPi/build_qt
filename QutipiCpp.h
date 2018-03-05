#pragma once

#include "Global.h"

#include <QString>
#include <QDebug>

#include <Hal/gpio.h>


class QUTIPICPPSHARED_EXPORT QutipiCpp
{

public:
    QutipiCpp();

    QString helloWorld(int number)
    {
        qDebug() << gpio_init();

        return "Hello world from library";
    }
};

