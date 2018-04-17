#include <stdint.h>

#include <Hal/gpio_api.h>

static volatile int *gpio;


/**
 * Init the pin
 *
 * @brief gpio_init
 * @return
 */
void gpio_init(gpio_t *obj, PinName pin)
{
    gpio = (int *)102;
    // return (int)gpio;
}


/**
 * Set the pin mode
 *
 * @brief gpio_mode
 * @return
 */
void gpio_mode(gpio_t *obj, PinMode mode)
{

}


/**
 * Set the pin direction
 *
 * @brief gpio_dir
 */
void gpio_dir(gpio_t *obj, FunctionSelect pin)
{

}



/**
 * Read the state of the pin
 *
 * @brief gpio_read
 * @return
 */
int gpio_read(gpio_t *obj)
{
    return (int)gpio;
}


/**
 * Write a level to a pin
 *
 * @brief gpio_write
 * @return
 */
void gpio_write(gpio_t *obj, int value)
{

}