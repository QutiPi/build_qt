#include <device.h>

/**
 * Open bus
 *
 * @brief bus
 * @param location
 * @param address
 * @param timeout
 * @return
 */
int i2c_open(char *location, char id, int timeout)
{
    return 1;
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
bool i2c_write(char bus, char* buf, int length)
{
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
bool i2c_read(char bus, char* buf, int length)
{
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
     // Return success
    return true;
}

