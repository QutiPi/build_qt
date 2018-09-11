#include <stdio.h>
#include <Hal/delay_api.h>

/**
 * Pause for a set period of time
 *
 * @brief delay
 * @param time
 * @param unit
 */
void delay(int time, TimeUnits unit)
{
    // Select the unit type
    if(unit == US)
    {
        delay_microseconds(time);
    }
    else if(unit == MS)
    {
        delay_milliseconds(time);
    }
    else if(unit == S)
    {
        delay_seconds(time);
    }
}


/**
 * Pause for X microseconds
 * 		NOTE: 	Raspberry pi nanosleep take 100 uS
 * 				hence we will use a for loop for more accurcy
 * 				when below 150uS
 *
 * @brief delay_microseconds
 * @param time
 */
void delay_microseconds(int time)
{

}


/**
 * Pause for X milliseconds
 *      NOTE: We also take into account the Pi's average
 *            delay time to call nanosleep
 *
 * @brief delay_milliseconds
 * @param time
 */
void delay_milliseconds(int time)
{
}


/**
 * Pause for X seconds
 *
 * @brief delay_seconds
 * @param time
 */
void delay_seconds(int time)
{

}

