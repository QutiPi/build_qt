#pragma once


namespace QutiPi { namespace Drivers
{

    class I2C
    {

    public:
        I2C();

        void writeBytes(I2C device, char buf, char length);

        void readBtyes(I2C device, char buf, char length);

        void updateBuffer(char buffer, int id, char bit, char value);

    };

}}
