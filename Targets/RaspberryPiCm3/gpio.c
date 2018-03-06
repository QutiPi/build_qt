#include <stdint.h>

static volatile int *gpio;

int gpio_init()
{
    gpio = (int *)102;
    return (int)gpio;
}

int gpio_read()
{
    return (int)gpio;
}
