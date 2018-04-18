#include <stdio.h>
#include <sys/time.h>

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
    // Was requested time less than 150uS?
    if(time <= 150)
    {
        // Create
        struct timeval current, length, result ;

        // Get the current time
        gettimeofday(&current, NULL);

        // Set time values
        length.tv_sec  = time / 1000000 ;
        length.tv_usec = time % 1000000 ;

        // Add current and delay time into result
        timeradd(&current, &length, &result) ;

        // Loop while current time is less than result time
        while (timercmp(&current, &result, <))
          gettimeofday (&current, NULL);
    }
    else
    {
        // Create
        struct timespec delay;

        // Nano sleep takes atleast 80 uS to call on the pi
        if(time > 80)
            time -= 80;

        // Set times
        delay.tv_sec = (time / 1000000);
        delay.tv_nsec = (long)((time % 1000000) * 1000L) ;

        // Sleep
        nanosleep (&delay, NULL) ;
    }
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
    // Create
    struct timespec delay;

    // Nano sleep takes atleast 80 uS to call on the pi
    if(time > 1)
        time -= 1;

    // Set times
    delay.tv_sec = (time / 1000);
    delay.tv_nsec = (long)((time % 1000) * 1000000);

    // Sleep
    nanosleep (&delay, NULL) ;
}


/**
 * Pause for X seconds
 *
 * @brief delay_seconds
 * @param time
 */
void delay_seconds(int time)
{
    // Create
    struct timespec delay;

    // Set times
    delay.tv_sec = time;
    delay.tv_nsec = 0;

    // Sleep
    nanosleep (&delay, NULL) ;
}

