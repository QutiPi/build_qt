#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Open bus
     *
     * @brief bus
     * @param location
     * @param address
     * @param timeout
     * @return
     */
    int i2c_open(char* location, int timeout = 1000);

    /**
     * Set the bus address
     *
     * @brief i2c_address
     * @param bus
     * @param id
     * @return
     */
    int i2c_address(int bus, char id);

    /**
     * Write to i2c bus
     *
     * @brief i2c_write
     * @param bus
     * @param buf
     * @param length
     * @return
     */
    bool i2c_write(char bus, char* buf, int length);

    /**
     * Read from i2c bus
     *
     * @brief i2c_read
     * @param bus
     * @param buf
     * @param length
     * @return
     */
    bool i2c_read(char bus, char* buf, int length);

    /**
     * Close an i2c bus
     *
     * @brief i2c_close
     * @param bus
     * @return
     */
    bool i2c_close(int bus);

#ifdef __cplusplus
}
#endif

