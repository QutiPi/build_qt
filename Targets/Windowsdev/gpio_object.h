#pragma once

#include <objects.h>


#ifdef __cplusplus
extern "C" {
#endif

    // @todo
    typedef struct {
        PinName pin;
    } gpio_t;


    // Types of edge trigger supported
    typedef enum {
        RISING = 0,
        FALLING = 1,
        BOTH = 2,
    } gpio_edge_t;


    // Current GPIO ISR
    typedef void (*callback_t) ();
    typedef struct
    {
       PinName gpio;
       gpio_edge_t edge;
       int timeout;
       callback_t function;
    } gpio_isr_t;



#ifdef __cplusplus
}
#endif
