#include <fcntl.h>

#include <device.h>

#include <Hal/pwm_api.h>

/**
 * Setup the pwm ready for use
 *
 * @brief pwm_setup
 * @return
 */
bool pwm_setup()
{
    return true;
}


/**
 * Destory PWM
 *
 * @brief pwm_destory
 * @return
 */
bool pwm_destory()
{
    return true;
}


/**
 * Set which mode the pwm should be in
 *
 * @brief pwm_set_mode
 * @param pin
 * @param mode
 */
void pwm_set_mode(PinName pin, PwmModes mode)
{

}


/**
 * Set the range of the pwm
 *
 * @brief pwm_set_range
 * @param pin
 * @param range
 */
void pwm_set_range(PinName pin, int range)
{

}


/**
 * Set the pwm clock
 *
 * @brief pwm_set_clock
 * @param pin
 * @param divisor
 */
void pwm_set_clock(PinName pin, int divisor)
{

}


/**
 * Write a value to the pwm
 *
 * @brief pwm_set_value
 * @param pin
 * @param value
 */
void pwm_write(PinName pin, int value)
{

}

