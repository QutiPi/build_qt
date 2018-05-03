#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <device.h>

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Setup gpio clock
     *
     * @brief gpclk_setup
     * @return
     */
    bool gpclk_setup();


    /**
     * Cleanup
     *
     * @brief gpclk_destory
     */
    void gpclk_destory();


    /**
     * Set gpio clock
     *
     * @brief set_gpclock
     * @param pin
     * @param frequency
     */
    void set_gpclock(PinName pin, int frequency);

#ifdef __cplusplus
}
#endif
