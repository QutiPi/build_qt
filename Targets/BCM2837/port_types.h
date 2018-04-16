#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    // Define the possiable alternative functions
    typedef enum
    {
        INPUT  = 0,
        OUTPUT  = 1,
        ALT0  = 4,
        ALT1  = 5,
        ALT2  = 6,
        ALT3  = 7,
        ALT4  = 3,
        ALT5  = 2,
        MASK  = 7
    } FunctionSelect;

    // Define the peripherals
    typedef enum
    {
        SPI_0  = 0,
        SPI_1  = 1,
        I2C_0  = 3,
        I2C_1  = 4,
        PWM_0  = 5,
        PWM_1  = 6,
        UART_0  = 7,
        UART_1  = 8,
    } FunctionPeripherals;

    // Set pin names

#ifdef __cplusplus
}
#endif
