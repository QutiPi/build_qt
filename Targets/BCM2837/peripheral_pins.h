#pragma once

#include "pin_names.h"

#ifdef __cplusplus
extern "C" {
#endif

    // I2C pin to peripheral mapping
    extern const PinMap PinMap_I2C_SDA[];
    extern const PinMap PinMap_I2C_SCL[];

    // UART pin to peripheral mapping
    extern const PinMap PinMap_UART_TX[];
    extern const PinMap PinMap_UART_RX[];
    extern const PinMap PinMap_UART_CT[];
    extern const PinMap PinMap_UART_RT[];

    // SPI pin to peripheral mapping
    extern const PinMap PinMap_SPI_SCLK[];
    extern const PinMap PinMap_SPI_MOSI[];
    extern const PinMap PinMap_SPI_MISO[];
    extern const PinMap PinMap_SPI_SSEL[];

    // PWM pin to peripheral mapping
    extern const PinMap PinMap_PWM[];

    // SDIO interface pin to peripheral mapping
    extern const PinMap PinMap_SDIO_CLK[];
    extern const PinMap PinMap_SDIO_CMD[];
    extern const PinMap PinMap_SDIO_DATA0[];
    extern const PinMap PinMap_SDIO_DATA1[];
    extern const PinMap PinMap_SDIO_DATA2[];
    extern const PinMap PinMap_SDIO_DATA3[];

    // General purpose clock pin to peripheral mapping
    extern const PinMap PinMap_GPCLK[];

    // PCM pin to peripheral mapping
    extern const PinMap PinMap_PCM_CLK[];
    extern const PinMap PinMap_PCM_FS[];
    extern const PinMap PinMap_PCM_DIN[];
    extern const PinMap PinMap_PCM_DOUT[];

#ifdef __cplusplus
}
#endif
