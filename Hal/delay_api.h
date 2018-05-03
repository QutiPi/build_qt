#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Delay by set unit
     *
     * @brief delay
     * @param time
     * @param unit
     */
    void delay(int time, TimeUnits unit);


    /**
     * Delay by microseconds
     *
     * @brief delay_microseconds
     * @param time
     */
    void delay_microseconds(int time);

    /**
     * Delay by millis seconds
     *
     * @brief delay_milliseconds
     * @param time
     */
    void delay_milliseconds(int time);

    /**
     * Delay by seconds
     *
     * @brief delay_seconds
     * @param time
     */
    void delay_seconds(int time);

#ifdef __cplusplus
}
#endif
