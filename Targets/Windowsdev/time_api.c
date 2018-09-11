#include <stdint.h>

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

    return 1;
}


/**
 * Return time value in microseconds
 *
 * @brief micros
 * @return
 */
unsigned int micros()
{
   return 1;
}


/**
 * Return time value in milliseconds
 *
 * @brief millis
 * @return
 */
unsigned int millis()
{
    return 1;
}


/**
 * Return time value in seconds
 *
 * @brief seconds
 * @return
 */
unsigned int seconds()
{
    return 1;
}

