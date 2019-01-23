#include "MCP3424.h"

#include <fcntl.h>
#include <iostream>
#include <QDebug>

#include "Hal/delay_api.h"
#include "Hal/i2c_api.h"

namespace QutiPi { namespace Hardware { namespace ADC
{

    /**
     * Class constructure performs
     *      - configures ADC
     *
     * @brief MCP3424::MCP3424
     */
    MCP3424::MCP3424(Device ic)
        :   I2C(ic)
    {
        // Set up the IC with some defaults
        configure(Port::One, Bitrate::Twelve, Conversion::Continious, Gain::One);
    }

    MCP3424::MCP3424(std::string location, char address, int timeout)
        :   I2C([&location, &address, &timeout] () -> Device {
                Device settings;
                settings.address = 0x6c;
                settings.location = "/dev/i2c-1";
                return settings;
            }())
    {
        // Set up the IC with some defaults
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
    void MCP3424::configure(Port port, Bitrate res, Conversion mode, Gain gain) noexcept
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
     * Not recommed, please stay type strict for your own benifit!
     * However the below does allow easier use when dynamically calling a port
     *
     * @brief MCP3424::read
     * @param port
     * @param type
     * @return
     */
    double MCP3424::read(int port, Type type)
    {
        // Check range is allowed
        if(port > 4 || port < 1)
            throw std::range_error("Provided port range is outside what is available 1-4");

        // Call type strict implimentation
        switch(port)
        {
            case 1:
                return read(Port::One, type);
            break;
            case 2:
                return read(Port::Two, type);
            break;
            case 3:
                return read(Port::Three, type);
            break;
            default:
                return read(Port::Four, type);
            break;
        }
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
        int value = 0;

        // Default the sign bit to false
        signbit = false;

        // Has the set channel changed?
        if(m_port != port)
        {
            // Set the new channel
            setChannel(port);
        }

        // If one shot request a read
        if(m_mode == Conversion::Oneshot)
        {
            // Set the read flag
            m_configuration[0] = updateBuffer(m_configuration, 0, 7, 1);

            // Write the command
            openBus(m_ic);
            assignAddress(m_ic);
            writeBytes(m_ic, m_configuration, 1);
            closeBus();

            // Unset the read flag
            m_configuration[0] = updateBuffer(m_configuration, 0, 7, 0);
        }

        // Request data
        openBus(m_ic);
        assignAddress(m_ic);
        writeBytes(m_ic, m_configuration, 1);

        // Read & convert the data
        switch(m_resolution)
        {
            case Bitrate::Twelve:
                // Read response
                readBtyes(m_ic, buffer, 4);

                // Determin value
                value = ((buffer[0] & 15) << 8) | buffer[1];
                if ((value >> 11) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 11);
                }
                break;
            case Bitrate::Fourteen:
                // Read response
                readBtyes(m_ic, buffer, 4);

                // Determin value
                value = ((buffer[0] & 63) << 8) | buffer[1];
                if ((value >> 13) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 13);
                }
                break;
            case Bitrate::Sixteen:
                // Read response
                readBtyes(m_ic, buffer, 4);

                // Determin value
                value = (buffer[0] << 8) | buffer[1];
                if ((value >> 15) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 15);
                }
                break;
            case Bitrate::Eighteen:
                // Read response
                readBtyes(m_ic, buffer, 4);

                // Determin value
                value = ((buffer[0] & 0x03) << 16) | (buffer[1] << 8) | buffer[2];
                if ((value >> 17) & 1)
                {
                    signbit = true;
                    value &= ~(1 << 17);
                }
                break;
        }

        // Close the bus
        closeBus();

        // Return if we just want to raw digital value
        if(type == Type::Digital)
            return value;

        // Convert raw digital value to the voltage
        double convert = voltage(value, signbit);

        // If single ended we need to double the voltage calculation
        // If differential reading we can return the standard voltage calculation
        return (type == Type::VoltageSigleEnded) ? convert * 2 : convert ;
    }


    /**
     * Convert digital int to voltage
     *
     * @brief MCP3424::voltage
     * @param digital
     * @return
     */
    double MCP3424::voltage(int digital, bool useSign) noexcept
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
    void MCP3424::setChannel(Port port) noexcept
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
    void MCP3424::setResolution(Bitrate res) noexcept
    {
        // Update the current channel cache
        m_resolution = res;

        // Select which lsb to use
        Lsb t_lsb;

        switch(res)
        {
            case Bitrate::Twelve:
                m_lsb = (double) t_lsb.Twelve;
                m_configuration[0] = updateBuffer(m_configuration, 0, 2, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 3, 0);
                break;
            case Bitrate::Fourteen:
                m_lsb = (double) t_lsb.Fourteen;
                m_configuration[0] = updateBuffer(m_configuration, 0, 2, 1);
                m_configuration[0] = updateBuffer(m_configuration, 0, 3, 0);
                break;
            case Bitrate::Sixteen:
                m_lsb = (double) t_lsb.Sixteen;
                m_configuration[0] = updateBuffer(m_configuration, 0, 2, 0);
                m_configuration[0] = updateBuffer(m_configuration, 0, 3, 1);
                break;
            case Bitrate::Eighteen:
                m_lsb = (double) t_lsb.Eighteen;
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
    void MCP3424::setConversion(Conversion mode) noexcept
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
    void MCP3424::setGain(Gain gain) noexcept
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

