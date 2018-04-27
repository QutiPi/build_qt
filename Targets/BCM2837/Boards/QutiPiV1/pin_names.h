#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    // Broadcom
    #define	BCM_PASSWORD 0x5A000000
    #define	BCM_PORT_SHIFT 0x3F000000

    // Port states
    typedef enum {
        NONE = 0,           // 0b00
        DOWN = 1,           // 0b01
        UP   = 2,           // 0b10
    } PinMode;


    // Pin directions
    typedef enum {
        PIN_INPUT = 0,    // 0b000
        PIN_OUTPUT = 1,   // 0b001
    } PinDirection;


    // Define the possiable alternative functions
    typedef enum
    {
        INPUT  = 0,   // 0b000
        OUTPUT = 1,   // 0b001
        ALT_0  = 4,    // 0b100
        ALT_1  = 5,    // 0b101
        ALT_2  = 6,    // 0b110
        ALT_3  = 7,    // 0b111
        ALT_4  = 3,    // 0b011
        ALT_5  = 2,    // 0b010
    } FunctionSelect;

    // Define the peripherals @todo assign correct values
    typedef enum
    {
        // SPI Buses
        SPI_0  = 0,
        SPI_1  = 1,
        SPI_2  = 2,

        // I2C Buses
        I2C_0  = 3,
        I2C_1  = 4,

        // PWM Controllers
        PWM_0  = 5,
        PWM_1  = 6,

        // UART Hardware
        UART_0  = 7,
        UART_1  = 8,

        // I2S/ PCM Controllers
        PCM_0 = 9,

        // General purpose clock controller
        GPCLK_0 = 10,
        GPCLK_1 = 11,
        GPCLK_2 = 12,

        // SDIO controller
        SDIO_1 = 13,

        // Below should not need mappings but keep in mind for now
        // DMA Controllers
        // Timers
        // Interrrupt controllers

    } FunctionPeripherals;

    // Set human readable pin names
    typedef enum {
        // Map all GPIO avliable on the board
        GPIO_0 = 0,
        GPIO_1 = 1,
        GPIO_2 = 2,
        GPIO_3 = 3,
        GPIO_4 = 4,
        GPIO_5 = 5,
        GPIO_6 = 6,
        GPIO_7 = 7,
        GPIO_8 = 8,
        GPIO_9 = 9,
        GPIO_10 = 10,
        GPIO_11 = 11,
        GPIO_12 = 12,
        GPIO_13 = 13,
        GPIO_14 = 14,
        GPIO_15 = 15,
        GPIO_16 = 16,
        GPIO_17 = 17,
        GPIO_18 = 18,
        GPIO_19 = 19,
        GPIO_20 = 20,
        GPIO_21 = 21,
        GPIO_22 = 22,
        GPIO_23 = 23,
        GPIO_24 = 24,
        GPIO_25 = 25,
        GPIO_26 = 26,
        GPIO_27 = 27,
        GPIO_28 = 28,
        GPIO_29 = 29,
        GPIO_30 = 30,
        GPIO_31 = 31,
        GPIO_32 = 32,
        GPIO_33 = 33,
        GPIO_34 = 34,
        GPIO_35 = 35,
        GPIO_36 = 36,
        GPIO_37 = 37,
        GPIO_38 = 38,
        GPIO_39 = 39,
        GPIO_40 = 40,
        GPIO_41 = 41,
        GPIO_42 = 42,
        GPIO_43 = 43,
        GPIO_44 = 44,
        GPIO_45 = 45,

        // The below are commented out as they are not avaliable to use but do exist
        // GPIO_46 = 46,
        // GPIO_47 = 47,
        // GPIO_48 = 48,
        // GPIO_49 = 49,
        // GPIO_50 = 50,
        // GPIO_51 = 51,
        // GPIO_52 = 52,
        // GPIO_53 = 53,

        // The Qutipi board assumed some default pin functions
        // which were select / configured to gain maxium functionality
        SPI0_CE1 = GPIO_7,
        SPI0_CE0 = GPIO_8,
        SPI0_MOSI = GPIO_10,
        SPI0_MISO = GPIO_9,
        SPI0_CLK = GPIO_11,

        SPI1_CE2 = GPIO_16,
        SPI1_CE1 = GPIO_17,
        SPI1_CE0 = GPIO_18,
        SPI1_MOSI = GPIO_20,
        SPI1_MISO = GPIO_19,
        SPI1_CLK = GPIO_21,

        I2C0_SDA = GPIO_0,
        I2C0_SCL = GPIO_1,

        I2C1_SDA = GPIO_2,
        I2C1_SCL = GPIO_3,

        UART0_TX = GPIO_14,
        UART0_RX = GPIO_15,

        UART1_TX = GPIO_32,
        UART1_RX = GPIO_33,

        GPCLK0 = GPIO_4,
        GPCLK1 = GPIO_5,
        GPCLK2 = GPIO_6,

        PWM0 = GPIO_12,
        PWM1 = GPIO_13,

        SD1_CLK = GPIO_22,
        SD1_CMD = GPIO_23,
        SD1_DATA0 = GPIO_24,
        SD1_DATA1 = GPIO_25,
        SD1_DATA2 = GPIO_26,
        SD1_DATA3 = GPIO_27,

        PCM0_CLK = GPIO_28,
        PCM0_FS = GPIO_29,
        PCM0_DIN = GPIO_30,
        PCM0_OUT = GPIO_31,

        // Not connected
        NC = (int)0xFFFFFFFF
    } PinName;


    typedef struct {
        PinName pin;
        FunctionPeripherals peripheral;
        FunctionSelect function;
    } PinMap;

#ifdef __cplusplus
}
#endif
