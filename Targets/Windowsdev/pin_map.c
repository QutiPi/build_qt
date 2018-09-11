#include <pin_names.h>
#include <Hal/pin_map.h>
#include <Hal/delay_api.h>
#include <device.h>
#include <stdio.h>



/**
 * Save the pin mode manual as read backs are not possiable
 */
volatile PinMode *pin_modes_cache[54];


/**
 * Setup the GPIOs for use
 *
 * @brief pinmap_setup
 */
bool pinmap_setup()
{
    // We have success
    return true;
}


/**
 * Cleanup pin mappings
 *
 * @brief pinmap_destory
 */
void pinmap_destory()
{
}


/**
 * Select which function the pin is to be used for
 *
 * @brief pin_function
 * @param pin
 * @param function
 */
void pin_function(PinName pin, FunctionSelect function)
{

}


/**
 * Returns the current function selected
 *
 * @brief pin_function_current
 * @param pin
 * @return
 */
FunctionSelect pin_function_current(PinName pin)
{
    // Set the return
    return 1;
}


/**
 * Set the input pin mode
 *      - Pull up, Pull down etc
 *
 * @brief pin_mode
 * @param pin
 * @param mode
 */
void pin_mode(PinName pin, PinMode mode)
{
    // Wait 150 cyles
    delay_microseconds(5);

    // Wait 150 cyles
    delay_microseconds(5);

}

/**
 * Return the current pin configuration
 *
 * @brief pin_mode_current
 * @param pin
 * @return
 */
PinMode pin_mode_current(PinName pin)
{
    return *pin_modes_cache[pin];
}


/**
 * Check peripheral pins mappings to ensure pin has selected alternative function
 *   and return the function ID
 *
 * @TODO
 * @brief assert_functionality
 * @param pin
 * @param function
 * @return
 */
FunctionPeripherals assert_functionality(PinName pin, FunctionSelect function)
{
    return GPIO;
}


