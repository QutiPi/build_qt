#pragma once

#include <string>

#include <device.h>

#include <Hal/i2c_api.h>

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

            Device m_ic;

            int bitSize = 7;

            int m_bus = -1;

            I2C(Device ic);

            int openBus(Device device);

            void assignAddress(Device device);

            void writeBytes(Device device, char* buf, int length);

            char readBtyes(Device device, char* buf, int length);

            void closeBus()
            {
                i2c_close(m_bus);
                m_bus = -1;
            };

            char updateBuffer(char buffer[], int id, char bit, char value);

            template<typename E>
            constexpr auto toUnderlying(E e) noexcept
            {
                return static_cast<std::underlying_type_t<E>>(e);
            }

    };

}}
