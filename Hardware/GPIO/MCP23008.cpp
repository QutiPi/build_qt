#include "MCP23008.h"


#include <fcntl.h>
#include <iostream>
#include <QDebug>

#include "Hal/delay_api.h"
#include "Hal/i2c_api.h"

namespace QutiPi { namespace Hardware { namespace GPIO
{

    /**
     * Class constructure performs
     *
     * @brief MCP3424::MCP3424
     */
    MCP23008::MCP23008(Device ic)
        :   I2C(ic)
    {
        init();
    }


    MCP23008::MCP23008(std::string location, char address, int timeout)
        :   I2C([&location, &address, &timeout] () -> Device {
                Device settings;
                settings.address = address;
                settings.location = location;
                settings.timeout = timeout;
                return settings;
            }())
    {
        init();
    }


    /**
     * Class destructor performs
     *
     * @brief MCP23008::~MCP23008
     */
    MCP23008::~MCP23008()
    {
    }


    /**
     * Set the initail configuration of the device
     *
     * @brief MCP23008::setInitConfig
     */
    void MCP23008::init()
    {
        // Set IOCON register
        writeRegisterBytes(m_addresses.iocon_a, m_configurations.config_a);

        // Get uptodate states for gpio
        m_configurations.port_a = readRegisterBytes(m_addresses.gpio_a);

        // Set directions for all pins to input
        m_configurations.direction_a = 0xff;
        writeRegisterBytes(m_addresses.iodir_a, m_configurations.direction_a);

        // Set pull ups to off for all pins
        setBankPullUp(Bank::A, PullUp::Disable);

        // Set invert logic to disabled all pins
        setBankPolarity(Bank::A, Polarity::Same);
    }


    /**
     * Set whether the pin is an output or input for a pin
     *
     * @brief MCP23008::setDirection
     * @param port
     * @param direction
     */
    void MCP23008::setDirection(Port port, Direction direction)
    {
        // Cast to the relivent types
        int nPin = toUnderlying(port);
        char nDir = static_cast<char>(direction);

        if(nPin >= 0 && nPin < 8)
        {
            // Update port config
            qDebug() << "Dir 1: " << (int) m_configurations.direction_a;
            m_configurations.direction_a = updateBuffer(&m_configurations.direction_a, 0, nPin, nDir);

            // Write command
            writeRegisterBytes(m_addresses.iodir_a, m_configurations.direction_a);

            qDebug() << "Direction set: " << (int)m_configurations.direction_a;
        }
    }

    void MCP23008::setBankDirection(Bank bank, Direction direction)
    {
        if(bank == Bank::A)
        {
            m_configurations.direction_a = (direction == Direction::Input) ? 0xff : 0x00;
            writeRegisterBytes(m_addresses.iodir_a, m_configurations.direction_a);
        }
    }


    /**
     * Enable or disable a 100k pull up resistor for a pin
     *
     * @brief MCP23008::setPullUp
     * @param port
     * @param pullup
     */
    void MCP23008::setPullUp(Port port, PullUp pullup)
    {
        // Cast to the relivent types
        int nPin = toUnderlying(port);
        char nDir = static_cast<char>(pullup);

        if(nPin >= 0 && nPin < 8)
        {
            // Update port config
            m_configurations.pullup_a = updateBuffer(&m_configurations.pullup_a, 0, nPin, nDir);

            // Write command
            writeRegisterBytes(m_addresses.gppu_a, m_configurations.pullup_a);

            qDebug() << "Pullup set: " << (int)m_configurations.pullup_a;
        }
    }

    void MCP23008::setBankPullUp(Bank bank, PullUp pullup)
    {
        if(bank == Bank::A)
        {
            m_configurations.pullup_a = (pullup == PullUp::Enable) ? 0xff : 0x00;
            writeRegisterBytes(m_addresses.gppu_a, m_configurations.pullup_a);
        }
    }


    /**
     * Polarity of output logic can be inverted if required for a pin
     *
     * @brief MCP23008::setPolarity
     * @param port
     * @param polarity
     */
    void MCP23008::setPolarity(Port port, Polarity polarity)
    {
        // Cast to the relivent types
        int nPin = toUnderlying(port);
        char nDir = static_cast<char>(polarity);

        if(nPin >= 0 && nPin < 8)
        {
            // Update port config
            m_configurations.polarity_a = updateBuffer(&m_configurations.polarity_a, 0, nPin, nDir);

            // Write command
            writeRegisterBytes(m_addresses.ipol_a, m_configurations.polarity_a);

            qDebug() << "Polarity set: " << (int)m_configurations.polarity_a;
        }
    }

    void MCP23008::setBankPolarity(Bank bank, Polarity polarity)
    {
        if(bank == Bank::A)
        {
            m_configurations.polarity_a = (polarity == Polarity::Inverted) ? 0xff : 0x00;
            writeRegisterBytes(m_addresses.ipol_a, m_configurations.polarity_a);
        }
    }


    /**
     * Write a value to a pin
     *
     * @brief MCP23008::write
     * @param port
     * @param state
     */
    void MCP23008::write(Port port, State state)
    {
        // Cast to the relivent types
        int nPin = toUnderlying(port);
        char nDir = static_cast<char>(state);

        if(nPin >= 0 && nPin < 8)
        {
            // Update port config
            m_configurations.port_a = updateBuffer(&m_configurations.port_a, 0, nPin, nDir);

            // Write command
            writeRegisterBytes(m_addresses.gpio_a, m_configurations.port_a);
        }
    }

    void MCP23008::registerWrite(Bank bank, State state)
    {
        if(bank == Bank::A)
        {
            m_configurations.polarity_a = (state == State::High) ? 0xff : 0x00;
            writeRegisterBytes(m_addresses.ipol_a, m_configurations.polarity_a);
        }
    }


    /**
     * Read a value from a pin
     *
     * @brief MCP23008::read
     * @param port
     * @return
     */
    int MCP23008::read(Port port)
    {
        // Cast to the relivent types
        int nPin = toUnderlying(port);

        if(nPin >= 0 && nPin < 8)
        {
            // Read command
            m_configurations.port_a = readRegisterBytes(m_addresses.gpio_a);

            // Check bit
            return checkBit(m_configurations.port_a, nPin);
        }

        return -1;
    }

    char MCP23008::registerRead(Bank bank)
    {
        if(bank == Bank::A)
        {
            // Read command
            m_configurations.port_a = readRegisterBytes(m_addresses.gpio_a);

            // Retrun register
            return m_configurations.port_a;
        }
    }


    /**
     * Helper for writing packages to selected register
     *
     * @brief MCP23008::writeRegisterBytes
     * @param reg
     * @param data
     */
    void MCP23008::writeRegisterBytes(char reg, char data)
    {
        // Open bus
        openBus(m_ic);

        // Assign address
        assignAddress(m_ic);

        // Create package
        char buffer[5];
        buffer[0] = reg;
        buffer[1] = data;

        // Write data
        writeBytes(m_ic, buffer, 2);

        // Close bus
        closeBus();
    }


    /**
     * Helper for reading packages to selected register
     *
     * @brief MCP23008::readRegisterBytes
     * @param reg
     * @param data
     */
    char MCP23008::readRegisterBytes(char reg)
    {
        // Open bus
        openBus(m_ic);

        // Assign address
        assignAddress(m_ic);

        // Set register
        char buffer[5];
        buffer[0] = reg;

        // Request register data
        writeBytes(m_ic, buffer, 1);

        // Read the register data
        readBtyes(m_ic, buffer, 1);

        // Close bus
        closeBus();

        // Return data
        return buffer[0];
    }


}}}
