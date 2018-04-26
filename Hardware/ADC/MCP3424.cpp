#include "MCP3424.h"

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <QDebug>

namespace QutiPi { namespace Hardware { namespace ADC
{

    /**
     * Class constructure performs
     *      - @todo
     *
     * @brief MCP3424::MCP3424
     */
    MCP3424::MCP3424(Device ic)
        :   m_ic(ic)
    {
        // Set up the IC
        configure(Port::One, Bitrate::Twelve, Conversion::Continious, Gain::One);
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
    void MCP3424::configure(Port port, Bitrate res, Conversion mode, Gain gain)
    {
        // Set the channel
        setChannel(port);

        // Set the bit rate
        setResolution(res);

        // Set conversion mode
        setConversion(mode);

        // Set Gain
        setGain(gain);
    }


    /**
     * Reads the value for a specified port
     *
     * @brief MCP3424::read
     * @param port the port number of the ADC
     *              - from 1:4
     * @return int voltage in digital format
     */
    double MCP3424::read(Port port, Type type)
    {
        // Set vars for holding data
        char buffer[10];
        long value = 0;

        // Default the sign bit to false
        signbit = false;

        // Set the channel
        setChannel(port);

        // If one shot request a read
        if(m_mode == Conversion::Oneshot)
        {
            m_configuration[0] = updateBuffer(m_configuration, 0, 7, 1);
            writeBytes(m_ic, *m_configuration, 1);
            m_configuration[0] = updateBuffer(m_configuration, 0, 7, 0);
        }

        // Read & convert the data
        switch(m_resolution)
        {
            case Bitrate::Twelve:
                readBtyes(m_ic, buffer, 2);
                value = ((buffer[0] & 15) << 8) | buffer[1];
                if ((value >> 11) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 11);
                }
                break;
            case Bitrate::Fourteen:
                readBtyes(m_ic, buffer, 2);
                value = ((buffer[0] & 63) << 8) | buffer[1];
                if ((value >> 13) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 13);
                }
                break;
            case Bitrate::Sixteen:
                readBtyes(m_ic, buffer, 2);
                value = (buffer[0] << 8) | buffer[1];
                if ((value >> 15) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 15);
                }
                break;
            case Bitrate::Eighteen:
                readBtyes(m_ic, buffer, 3);
                value = ((buffer[0] & 3) << 16) | (buffer[1] << 8) | buffer[2];
                if ((value >> 17) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 17);
                }
                break;
        }

        // Return if we just want to raw digital value
        if(type == Type::Digital)
            return value;

        // Convert raw digital value to the voltage
        double convert = voltage(value, signbit);

        if(type == Type::VoltageSigleEnded)
            return convert * 2;

        return convert;
    }


    /**
     * Convert digital int to voltage
     *
     * @brief MCP3424::voltage
     * @param digital
     * @return
     */
    double MCP3424::voltage(long digital, bool useSign)
    {
        if(useSign)
        {
            return ((double)digital * (m_lsb / (int) m_gain)) - (2.048 / ((int) m_gain * 2));
        }
        else
        {
            return ((double)digital * (m_lsb / (int) m_gain));
        }
    }


    /**
     * Select which channel the ADC should read from
     *
     * @brief MCP3424::setChannel
     * @param port
     */
    void MCP3424::setChannel(Port port)
    {
        // Update the current channel cache
        m_port = port;

        // Which channel?
        switch(port)
        {
            case Port::One:
                m_configuration[0] = updateBuffer(m_configuration, 0, 5, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 6, 0);
                break;
            case Port::Two:
                m_configuration[0] = updateBuffer(m_configuration, 0, 5, 1);
                m_configuration[0] = updateBuffer(m_configuration, 0, 6, 0);
                break;
            case Port::Three:
                m_configuration[0] = updateBuffer(m_configuration, 0, 5, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 6, 1);
                break;
            case Port::Four:
                m_configuration[0] = updateBuffer(m_configuration, 0, 5, 1);
                m_configuration[0] = updateBuffer(m_configuration, 0, 6, 1);
                break;
        }
    }

    /**
     * Set the resolution for reads
     *
     * @brief MCP3424::setResolution
     * @param res
     */
    void MCP3424::setResolution(Bitrate res)
    {
        // Update the current channel cache
        m_resolution = res;

        switch(res)
        {
            case Bitrate::Twelve:
                m_lsb = Lsb.Twelve;
                m_configuration[0] = updateBuffer(m_configuration, 0, 2, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 3, 0);
                break;
            case Bitrate::Fourteen:
                m_lsb = Lsb.Fourteen;
                m_configuration[0] = updateBuffer(m_configuration, 0, 2, 1);
                m_configuration[0] = updateBuffer(m_configuration, 0, 3, 0);
                break;
            case Bitrate::Sixteen:
                m_lsb = Lsb.Sixteen;
                m_configuration[0] = updateBuffer(m_configuration, 0, 2, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 3, 1);
                break;
            case Bitrate::Eighteen:
                m_lsb = Lsb.Eighteen;
                m_configuration[0] = updateBuffer(m_configuration, 0, 2, 1);
                m_configuration[0] = updateBuffer(m_configuration, 0, 3, 1);
                break;
        }
    }


    /**
     * Sets the conversion mode
     *
     * @brief MCP3424::setConversion
     * @param mode
     */
    void MCP3424::setConversion(Conversion mode)
    {
        // Update the current channel cache
        m_mode = mode;

        // One shot (low power) or continious (faster)
        switch(mode)
        {
            case Conversion::Continious:
                m_configuration[0] = updateBuffer(m_configuration, 0, 4, 1);
                break;
            case Conversion::Oneshot:
                m_configuration[0] = updateBuffer(m_configuration, 0, 4, 0);
                break;
        }
    }

    /**
     * Set the gain for the input
     *
     * @brief MCP3424::setGain
     * @param gain
     */
    void MCP3424::setGain(Gain gain)
    {
        // Update the current channel cache
        m_gain = gain;

        // The gain for the signal
        switch(gain)
        {
            case Gain::One:
                m_configuration[0] = updateBuffer(m_configuration, 0, 0, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 1, 0);
                break;
            case Gain::Two:
                m_configuration[0] = updateBuffer(m_configuration, 0, 0, 1);
                m_configuration[0] = updateBuffer(m_configuration, 0, 1, 0);
                break;
            case Gain::Four:
                m_configuration[0] = updateBuffer(m_configuration, 0, 0, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 1, 1);
                break;
            case Gain::Eight:
                m_configuration[0] = updateBuffer(m_configuration, 0, 0, 1);
                m_configuration[0] = updateBuffer(m_configuration, 0, 1, 1);
                break;
        }
    }


}}}

