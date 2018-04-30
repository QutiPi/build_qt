#include <pin_names.h>
#include <Hal/pin_map.h>
#include <Hal/delay_api.h>
#include <device.h>
#include <stdio.h>


/**
 * Define block size
 */
// #define BCM_GPIO_SIZE 0xB4
#define BCM_GPIO_SIZE (4*1024)


/**
 * Related registers
 */
#define GPPUD     37
#define GPPUDCLK0 38
#define GPPUDCLK1 39

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
    // Release memory if range more than once
    if(pinmap != MAP_FAILED || pinmap != NULL)
        munmap((void *)pinmap, BCM_GPIO_SIZE);

    // Handler
    int fd;

    // Open dev memory control
    if ((fd = open ("/dev/mem", O_RDWR | O_SYNC | O_CLOEXEC) ) < 0)
    {
      if ((fd = open ("/dev/gpiomem", O_RDWR | O_SYNC | O_CLOEXEC) ) < 0)
          return false;
    }

    // Map device to file system
    pinmap = (uint32_t *)mmap(0, BCM_GPIO_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, gpio_base);

    // We have success
    return true;
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
    // Which register should be look in
    int reg = pin / 10;

    // Where is the pins function info in the register
    int shift = (pin % 10) * 3;

    // What is the current function?
    unsigned int current = (*(pinmap + reg) >> shift) & 7;

    // If the function is different change it
    if(function != current)
    {
        // Set the new function
        (*(pinmap + reg) & ~(7 << shift)) | (function << shift);
    }
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
    // Which register should be look in
    int reg = pin / 10;

    // Where is the pins function info in the register
    int shift = (pin % 10) * 3;

    // Query register
    int alt = (*(pinmap + reg) >> shift) & 7;

    // Set the return
    return alt;
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
     // Set the control signal in GPPUD register
     *(pinmap + GPPUD) = mode;

    // Wait 150 cyles
    delay_microseconds(5);

    // Set GPPUDCLK0 / 1 to perform the update to GPPUD
    *(pinmap + GPPUDCLK0 + ((int)pin >> 5)) = 1 << ((int)pin & 31);

    // Wait 150 cyles
    delay_microseconds(5);

    // Unset the control signal in GPPUD register
    *(pinmap + GPPUD) = 0;

    // Set GPPUDCLK0 / 1 to remove clock signal
    *(pinmap + GPPUDCLK0 + (pin >> 5)) = 0;

    // Save the pin mode
    pin_modes_cache[(int) pin] = &mode;
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

