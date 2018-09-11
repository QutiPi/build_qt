#include <fcntl.h>

#include <device.h>

#include <Hal/gpclk_api.h>




/**
 * Setup the gpclk ready for use
 *
 * @brief gpclk_setup
 */
bool gpclk_setup()
{
    return true;
}


/**
 * Destroy setup gpclk
 */
void gpclk_destory()
{

}


/**
 * Assign a clock output to a GPIO pin
 *      NOTE: We assume the use of clock source 1 @19.2MHz
 *
 * @brief set_gpclock
 * @param pin
 * @param frequency
 */
void gpclk_frequency(PinName pin, int frequency)
{

}
