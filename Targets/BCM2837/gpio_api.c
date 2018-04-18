#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <Hal/gpio_api.h>
#include <Hal/pin_map.h>


/**
 * Hold referance to mapped gpio device in memory
 */
static volatile uint32_t *gpio = MAP_FAILED;


/**
 * Base address to access the GPIO clock
 */
static volatile unsigned int gpio_base = BCM_PORT_SHIFT + 0x00200000;


/**
 * Define block size
 */
#define BCM_GPIO_SIZE 0xB4


/**
 * Init the pin
 *
 * @brief gpio_init
 * @return
 */
void gpio_init(gpio_t *obj, PinName pin)
{
    // gpio = (int *)102;
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
