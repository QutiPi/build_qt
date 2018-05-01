#pragma once

#include <string>

#include <device.h>

namespace QutiPi { namespace Drivers
{

    class I2C
    {

        public:

            struct Device{
                std::string location;
                char address;
                int timeout = 1000;
            };

            int bitSize = 7;

            I2C();

            int configureBus(Device device);

            void writeBytes(Device device, char& buf, int length);

            char readBtyes(Device device, char *buf, int length);

            char updateBuffer(char buffer[], int id, char bit, char value);

    };

}}
