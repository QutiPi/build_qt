#pragma once

#include "MCP3424.h"

#include <device.h>

namespace QutiPi { namespace Hardware { namespace Hardware
{

    class MCP3424
    {
        // Allowed bit rates
        enum class Bitrate
        {
            Twelve = 12,
            Fourteen = 14,
            Sixteen = 16,
            Eighteen = 18
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

    public:
        MCP3424(I2C ic);
        MCP3424::~MCP3424();

        // Setup class
        void setup(I2C ic);

        // Read voltage level
        int read(Ports port);

        // Device configuration
        void setResolution(Bitrate res);
        void setConversion(Conversion mode);
        void setGain(Gain gain);

    };
}}}




