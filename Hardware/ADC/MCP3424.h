#pragma once

#include <device.h>

#include "Drivers/I2C.h"


namespace QutiPi { namespace Hardware { namespace ADC
{

    class MCP3424 : private Drivers::I2C
    {
        public:
            // Allowed bit rates
            enum class Bitrate
            {
                Twelve,
                Fourteen,
                Sixteen,
                Eighteen
            };

            // Allowed gains
            enum class Gain
            {
                One = 1,
                Two = 2,
                Four = 4,
                Eight = 8
            };

            // Allowed gains
            enum class Conversion
            {
                Oneshot = 0,
                Continious = 1,
            };

            // Allowed ports
            enum class Port
            {
                One = 1,
                Two = 2,
                Three = 3,
                Four = 4,
            };

            // Read types
            enum class Type
            {
                Digital,
                Voltage,
                VoltageSigleEnded
            };

            // Class setup and destory
            MCP3424(Device ic);
            MCP3424(std::string location, char address, int timeout = 1000);
            ~MCP3424();

            // Standard device type
            using Drivers::I2C::Device;

            // Setup class
            void configure(Port port, Bitrate res, Conversion mode, Gain gain) noexcept;

            // Read voltage level
            double read(Port port, Type type);
            double read(int port, Type type);

            // Convert to voltage
            double voltage(int digital, bool useSign) noexcept;

        private:
            // Current status of IC
            bool signbit = false;
            double m_lsb = 0;
            Bitrate m_resolution;
            Conversion m_mode;
            Gain m_gain;
            Port m_port;

            // The bitwise config
            char m_configuration[1];

            // Charactrisation
            struct Lsb
            {
                 double Twelve = 0.0005;
                 double Fourteen = 0.000125;
                 double Sixteen = 0.00003125;
                 double Eighteen = 0.0000078125;
            };

            // Device configuration
            void setChannel(Port port) noexcept;
            void setResolution(Bitrate res) noexcept;
            void setConversion(Conversion mode) noexcept;
            void setGain(Gain gain) noexcept;


    };
}}}




