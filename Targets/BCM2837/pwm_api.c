#include <fcntl.h>
#include <sys/mman.h>

#include <device.h>

#include <Hal/pwm_api.h>


/**
 * Hold referance to mapped pwm device in memory
 */
static volatile uint32_t *pwm = MAP_FAILED;


/**
 * Base address to access the pwm
 */
static volatile unsigned int pwm_base = BCM_PORT_SHIFT + 0x0020C000;


/**
 * Define block size
 */
#define BCM_PWM_SIZE 0x28


/**
 * PWM offsets for control and status registers
 */
#define BCM_PWM_CTL      0
#define BCM_PWM_STA      1
#define BCM_PWM_DMAC     2
#define BCM_PWM_RNG1     4
#define BCM_PWM_DAT1     5
#define BCM_PWM_FIFO     6
#define BCM_PWM_RNG2     8
#define BCM_PWM_DAT2     9

/**
 * PWM offsets
 *      TIP: try using bitwise operaters here
 *           http://bitwisecmd.com/
 */
#define	BCM_PWM_CLK_CTL 40
#define	BCM_PWM_CLK_DIV	41

#define BCM_PWM_CTL_MSEN2 (1<<15)
#define BCM_PWM_CTL_PWEN2 (1<<8)
#define BCM_PWM_CTL_MSEN1 (1<<7)
#define BCM_PWM_CTL_CLRF1 (1<<6)
#define BCM_PWM_CTL_USEF1 (1<<5)
#define BCM_PWM_CTL_MODE1 (1<<1)
#define BCM_PWM_CTL_PWEN1 (1<<0)


/**
 * Setup the pwm ready for use
 *
 * @brief pwm_setup
 * @return
 */
bool pwm_setup()
{

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

