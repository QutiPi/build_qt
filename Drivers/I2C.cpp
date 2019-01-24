#include "I2C.h"

#include <stdexcept>

#include <device.h>

#include <Hal/i2c_api.h>
#include <Hal/time_api.h>

#include "Exceptions/I2COpenError.h"
#include "Exceptions/I2CAddressError.h"
#include "Exceptions/I2CReadError.h"
#include "Exceptions/I2CWriteError.h"

#include <QDebug>


namespace QutiPi { namespace Drivers
{

    I2C::I2C(Device ic)
        : m_ic(ic)
    {

    }

    /**
     * Open a bus
     *
     * @brief I2C::openBus
     * @param device
     * @return
     */
    int I2C::openBus(Device device)
    {
        // Get location
        char *location = const_cast<char *>(device.location.c_str());

        // Open the I2C bus
        m_bus = i2c_open(location);

        // Error check
        if(m_bus < 0)
        {
            throw Exceptions::I2COpenError(device.location, device.address);
        }

        // Return handler
        return m_bus;
    }


    /**
     * Assign an id to the bus
     *
     * @brief I2C::assignAddress
     * @param device
     */
    void I2C::assignAddress(Device device)
    {
        // Return handler
        if(i2c_address(m_bus, device.address) < 0)
        {
           throw Exceptions::I2CAddressError(device.location, device.address);
        }
    }


    /**
     * Write a string of bytes to an I2C device
     *
     * @brief writeBytes
     * @param device location and address of IC to write to
     * @param buf The buffer of bits to write
     * @param length How large is the buffer
     */
    void I2C::writeBytes(Device device, char *buf, int length)
    {
        // Attempt to write the buffer to the device
        if (i2c_write(m_bus, buf, length) != true)
        {
            throw Exceptions::I2CWriteError(device.location, device.address);
        }
    }


    /**
     * Read an array of bytes from an I2C device into a buffer
     *
     * @brief readBtyes
     * @param device location and address of IC to write to
     * @param buf the buffer to read into
     * @param length how many bytes to read
     */
    char I2C::readBtyes(Device device, char* buf, int length)
    {
        // Starting time
        int startingTime = current_time(MS);

        // Request we want a read
        do
        {
            // Read bus
            i2c_read(m_bus, buf, length);

            // Check size of buffer
            if ((buf[length-1] >> bitSize) == 0)
                break;

            // Check time out
            if((current_time(MS) - startingTime) > device.timeout)
            {
                throw Exceptions::I2CReadError(device.location, device.address);
            }
        } while(true);

        return *buf;
    }


    /**
     * Update a buffers specific char value
     *      NOTE: Look at std::bitset as an alternative
     *
     * @brief updateBuffer
     * @param buffer The buffer to update
     * @param id The id of the char in the buffer
     * @param bit The bit location in the char to update
     * @param value The value to place in the postion
     */
    char I2C::updateBuffer(char buffer[], int id, char bit, char value)
    {
        if(value == 0)
        {
            return (buffer[id] &= ~(1 << bit));
        }
        else
        {
            return (buffer[id] |= 1 << bit);
        }
    }


    /**
     * Check status of bit within a byte
     *
     * @brief I2C::checkBit
     * @param byte
     * @param bit
     * @return
     */
    char I2C::checkBit(char byte, char bit)
    {
        if(byte & (1 << bit))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

}}
