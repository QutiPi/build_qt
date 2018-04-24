#pragma once

#include "MCP3424.h"

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
        enum class Ports
        {
            One = 1,
            Two = 2,
            Three = 3,
            Four = 4,
        };

        // Class setup and destory
        MCP3424(Device ic, Bitrate res);
        ~MCP3424();

        // Standard device type
        using Drivers::I2C::Device;

        // Setup class
        void setup(Device ic, Bitrate res);

        // Read voltage level
        int read(Ports port);

        // Device configuration
        void setResolution(Bitrate res);
        void setConversion(Conversion mode);
        void setGain(Gain gain);

    private:
        // Current status of IC
        bool signbit = false;
        Drivers::I2C::Device ic;
        Bitrate resolution;
        Conversion mode;
        Gain gain;

        // The bitwise config
        char configuration;

        // Charactrisation
        struct lsb
        {
             double Twelve = 0.0005;
             double Fourteen = 0.000125;
             double Sixteen = 0.00003125;
             double Eighteen = 0.0000078125;
        };

    };
}}}




