#pragma once

// Include useful c libs
#include <math.h>
#include <time.h>

// Include Hals
#include "Hal/delay_api.h"
#include "Hal/dma_api.h"
#include "Hal/gpclk_api.h"
#include "Hal/gpio_api.h"
#include "Hal/gpio_irq_api.h"
#include "Hal/pcm_api.h"
#include "Hal/pin_map.h"
#include "Hal/port_api.h"
#include "Hal/port_api.h"
#include "Hal/pwm_api.h"
#include "Hal/time_api.h"

// Include Drivers
#include "Drivers/I2C.h"
#include "Drivers/DigitalIn.h"
#include "Drivers/DigitalOut.h"

// Include Platform


/**
 * Configures and sets up QutiPi framework
 *
 * @brief setup
 */
void qutipi_setup()
{
    // Setup device memory mappings
    gpio_setup();
}
