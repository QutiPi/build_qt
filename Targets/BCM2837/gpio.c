#include <stdint.h>

static volatile int *gpio;


/**
 * Init the pin
 *
 * @brief gpio_init
 * @return
 */
void gpio_init()
{
    gpio = (int *)102;
    return (int)gpio;
}


/**
 * Set the pin mode
 *
 * @brief gpio_mode
 * @return
 */
void gpio_mode()
{

}


/**
 * Set the pin direction
 *
 * @brief gpio_dir
 */
void gpio_dir()
{

}



/**
 * Read the state of the pin
 *
 * @brief gpio_read
 * @return
 */
int gpio_read()
{
    return (int)gpio;
}


/**
 * Write a level to a pin
 *
 * @brief gpio_write
 * @return
 */
void gpio_write()
{

}
