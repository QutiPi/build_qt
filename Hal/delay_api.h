#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    // Delay shortcut
    void delay(int time, TimeUnits unit);

    // Delay ranges
    void delay_microseconds(int time);
    void delay_milliseconds(int time);
    void delay_seconds(int time);

#ifdef __cplusplus
}
#endif
