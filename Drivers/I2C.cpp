#include "I2C.h"

/*#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <stdexcept>*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdexcept>
#include <errno.h>
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#include <device.h>

#include <bitset>
#include <QDebug>


namespace QutiPi { namespace Drivers
{

    I2C::I2C()
    {

    }


    int I2C::configureBus(Device device)
    {
        // Open the I2C bus
        auto bus = open(device.location.c_str(), O_RDWR);

        // Check the bus is open
        if(bus < 0)
        {
            throw std::runtime_error("Failed to open i2c port for read write");
        }

        // Select the address
        auto address = ioctl(bus, I2C_SLAVE, device.address);

        // Check the address was set correctly
        if (address < 0)
        {
            throw std::runtime_error("Failed to write to i2c port for writing operation");
        }

        // Return handler
        return bus;
    }



    /**
     * Write a string of bytes to an I2C device
     *
     * @brief writeBytes
     * @param device location and address of IC to write to
     * @param buf The buffer of bits to write
     * @param length How large is the buffer
     */
    void I2C::writeBytes(Device device, char &buf, int length)
    {
        // Setup the bus @todo catch errors
        auto bus = configureBus(device);

        // Attempt to write the buffer to the device
        if (write(bus, &buf, length) != 1)
        {
            throw std::runtime_error("Failed to write to i2c device for write operation");
        }

        // Close the bus
        close(bus);
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
        // Setup the bus @todo catch errors
        auto bus = configureBus(device);

        // Request we want a read
        do
        {
            // Read bus
            read(bus, buf, length);

            // Check size of buffer
            if (!(buf[length] & (1 << bitSize)))
                break;

            // Check time out TODO

        } while(true);

        // Close the bus
        close(bus);
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
        else if(value == 1)
        {
            return (buffer[id] |= 1 << bit);
        }
        else
        {
            throw std::out_of_range("Value must be 0 or 1");
        }
    }

}}
