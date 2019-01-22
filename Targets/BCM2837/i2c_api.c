#include <device.h>

#include <stdio.h>
#include <stdlib.h>
//#include <stdexcept>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>


/**
 * Open bus
 *
 * @brief bus
 * @param location
 * @param address
 * @param timeout
 * @return
 */
int i2c_open(char* location, int timeout)
{
    // Open the bus
    int bus = open(location, O_RDWR);

    // Check bus exist
    if(bus < 0)
    {
        return -1;
    }

    // Return bus number
    return bus;
}




int i2c_address(int bus, char id)
{
    // Assigned the address
    int address = ioctl(bus, I2C_SLAVE, id);

    return address;
}

/**
 * Write to i2c bus
 *
 * @brief i2c_write
 * @param bus
 * @param buf
 * @param length
 * @return
 */
bool i2c_write(char bus, char *buf, int length)
{
    // Write to bus on linux
    if(write(bus, buf, length) == -1)
    {
        return false;
    }

    return true;
}


/**
 * Read from i2c bus
 *
 * @brief i2c_read
 * @param bus
 * @param buf
 * @param length
 * @return
 */
bool i2c_read(char bus, char *buf, int length)
{
    // Read bus on linux
    if(read(bus, buf, length) == -1)
    {
        return false;
    }

    return true;
}


/**
 * Close an i2c bus
 *
 * @brief i2c_close
 * @param bus
 * @return
 */
bool i2c_close(int bus)
{
    // Close linux bus
    close(bus);

    // Return success
    return true;
}

