#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    bool gpclk_setup();

    void gpclk_destory();

    void set_gpclock(PinName pin, int frequency);

#ifdef __cplusplus
}
#endif
