#include "MCP3424.h"

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


namespace QutiPi { namespace Hardware { namespace ADC
{

    /**
     * Class constructure performs
     *      - @todo
     *
     * @brief MCP3424::MCP3424
     */
    MCP3424::MCP3424(Device ic, Bitrate res = Bitrate::Twelve)
    {
        // Set up the IC
        setup(ic, res);
    }


    /**
     * Class detructure performs:
     *      - @todo
     *
     * @brief MCP3424::~MCP3424
     */
    MCP3424::~MCP3424()
    {

    }


    /**
     * Setup the IC
     *
     * @brief MCP3424::setup
     * @param ic
     * @param res
     */
    void MCP3424::setup(Device ic, Bitrate res)
    {

    }


    /**
     * Reads the value for a specified port
     *
     * @brief MCP3424::read
     * @param port the port number of the ADC
     *              - from 1:4
     * @return int voltage in digital format
     */
    int MCP3424::read(Ports port)
    {
        return 10;
    }


    void MCP3424::setResolution(Bitrate res)
    {

    }

    void MCP3424::setConversion(Conversion mode)
    {

    }

    void MCP3424::setGain(Gain gain)
    {

    }


}}}

