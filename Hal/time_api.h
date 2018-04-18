#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Return time stamp
    unsigned int current_time(TimeUnits unit);

    // Time
    unsigned int micros();
    unsigned int millis();
    unsigned int seconds();

#ifdef __cplusplus
}
#endif
