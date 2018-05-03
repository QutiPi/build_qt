#pragma once

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Retrun the current time
     *
     * @brief current_time
     * @param unit
     * @return
     */
    unsigned int current_time(TimeUnits unit);

    /**
     * Return time in micros
     *
     * @brief micros
     * @return
     */
    unsigned int micros();

    /**
     * Return time in milli seconds
     *
     * @brief millis
     * @return
     */
    unsigned int millis();

    /**
     * Return time in seconds
     *
     * @brief seconds
     * @return
     */
    unsigned int seconds();

#ifdef __cplusplus
}
#endif
