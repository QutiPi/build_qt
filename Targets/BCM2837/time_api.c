#include <stdint.h>
#include <sys/time.h>

#include <Hal/time_api.h>

/**
 * Return time value for selected unit
 *
 * @brief time
 * @param unit
 * @return
 */
unsigned int current_time(TimeUnits unit)
{
    // Select the unit type
    if(unit == US)
    {
        micros();
    }
    else if(unit == MS)
    {
        millis();
    }
    else if(unit == S)
    {
        seconds();
    }
}


/**
 * Return time value in microseconds
 *
 * @brief micros
 * @return
 */
unsigned int micros()
{
    // Create
    struct  timespec time;

    // Get clock time
    clock_gettime (CLOCK_MONOTONIC_RAW, &time) ;

    // return current time
    return (uint64_t)time.tv_sec * (uint64_t)1000000 + (uint64_t)(time.tv_nsec / 1000);
}


/**
 * Return time value in milliseconds
 *
 * @brief millis
 * @return
 */
unsigned int millis()
{
    // Create
    struct  timespec time;

    // Get clock time
    clock_gettime (CLOCK_MONOTONIC_RAW, &time) ;

    // return current time
    return (uint64_t)time.tv_sec * (uint64_t)1000 + (uint64_t)(time.tv_nsec / 1000000L);
}


/**
 * Return time value in seconds
 *
 * @brief seconds
 * @return
 */
unsigned int seconds()
{
    // Create
    struct  timespec time;

    // Get clock time
    clock_gettime (CLOCK_MONOTONIC_RAW, &time) ;

    // return current time
    return (uint64_t)time.tv_sec + (uint64_t)(time.tv_nsec / 1000000000L);
}

