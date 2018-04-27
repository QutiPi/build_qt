#include <Hal/gpio_api.h>


/**
 * Setup the GPIOs for use
 *
 * @brief gpio_setup
 */
void gpio_setup()
{
    pinmap_setup();
}


/**
 * Init the pin
 *
 * @brief gpio_init
 * @return
 */
void gpio_init(gpio_t *obj, PinName pin)
{
    // Fill the gpio object
    obj->pin = pin;

    // If pin is not connected end here
    if (pin == (PinName) NC) {
        return;
    }

    // Fill object with addtional required info
}


/**
 * Set the function of the pin
 *
 * @brief gpio_set
 * @param obj
 * @param mode
 */
void gpio_set(gpio_t *obj, FunctionSelect function)
{
    pin_function(obj->pin, function);
}


/**
 * Set the pin mode
 *      - Pull up, pull down, none etc
 *
 * @brief gpio_mode
 * @return
 */
void gpio_mode(gpio_t *obj, PinMode mode)
{
    pin_mode(obj->pin, mode);
}


/**
 * Set the pin direction
 *
 * @brief gpio_dir
 */
void gpio_dir(gpio_t *obj, PinDirection pin)
{
    if(pin == PIN_INPUT)
    {
       pin_function(obj->pin, INPUT);
    }
    else if(pin == PIN_OUTPUT)
    {
        pin_function(obj->pin, OUTPUT);
    }
}



/**
 * Read the state of the pin
 *
 * @brief gpio_read
 * @return
 */
int gpio_read(gpio_t *obj)
{
    return (int) 1;
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
