#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <Hal/pin_map.h>
#include <pin_names.h>


/**
 * Setup the GPIOs for use
 *
 * @brief pinmap_setup
 */
void pinmap_setup()
{
    // Release memory if range more than once
    if(pinmap != MAP_FAILED)
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
    // Which register should be look in
    int reg = pin / 10;

    // Where is the pins function info in the register
    int shift = (pin % 10) * 3;

    // Query register
    int alt = (*(pinmap + reg) >> shift) & 7;

    // Set the return
    return alt;
}


void pin_mode(PinName pin, PinMode mode)
{

}


PinMode pin_mode_current(PinName pin)
{

}

