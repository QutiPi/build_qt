#include "I2C.h"

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>


namespace QutiPi { namespace Drivers
{

    I2C::I2C()
    {

    }


    /**
     * Write a string of bytes to an I2C device
     *
     * @brief writeBytes
     * @param device location and address of IC to write to
     * @param buf The buffer of bits to write
     * @param length How large is the buffer
     */
    void writeBytes(I2C device, char buf, char length)
    {
        // Open the I2C bus

        // Check the device exsists

        // Write the buffer to the device
    }


    /**
     * Read an array of bytes from an I2C device into a buffer
     *
     * @brief readBtyes
     * @param device location and address of IC to write to
     * @param buf the buffer to read into
     * @param length how many bytes to read
     */
    void readBtyes(I2C device, char buf, char length)
    {
        // Open the I2C bus

        // Request we want a read

        // Read the response
    }


    /**
     * Update a buffers specific char value
     *
     * @brief updateBuffer
     * @param buffer The buffer to update
     * @param id The id of the char in the buffer
     * @param bit The bit location in the char to update
     * @param value The value to place in the postion
     */
    void updateBuffer(char buffer, int id, char bit, char value)
    {
        // Is value 0 or 1?
            // Update for 0
            // Update for 1
    }

}}
