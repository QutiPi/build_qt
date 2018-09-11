#include "I2C.h"

#include <stdexcept>

#include <device.h>

#include <Hal/i2c_api.h>
#include <Hal/time_api.h>


namespace QutiPi { namespace Drivers
{

    I2C::I2C()
    {

    }


    int I2C::configureBus(Device device)
    {
        // Get location
        char *location = const_cast<char *>(device.location.c_str());

        // Open the I2C bus
        int bus = i2c_open(location, device.address);

        // Error check
        if(bus == -1)
        {
           throw std::runtime_error("Failed to open i2c port for read write");
        }
        else if(bus == -2)
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
        if (i2c_write(bus, &buf, length) != true)
        {
            throw std::runtime_error("Failed to write to i2c device for write operation");
        }

        // Close the bus
        i2c_close(bus);
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

        // Starting time
        int startingTime = current_time(MS);

        // Request we want a read
        do
        {
            // Read bus
            i2c_read(bus, buf, length);

            // Check size of buffer
            if ((buf[length] >> bitSize) == 0)
                break;

            // Check time out
            if((current_time(MS) - startingTime) > device.timeout)
                break;

        } while(true);

        // Close the bus
        i2c_close(bus);

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
