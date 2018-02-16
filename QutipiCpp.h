#pragma once

#include "Global.h"

#include <QString>

class QUTIPICPPSHARED_EXPORT QutipiCpp
{

public:
    QutipiCpp();

    QString helloWorld(int number){
        return "Hello world from library: " + QString::number(number);
    }
};

