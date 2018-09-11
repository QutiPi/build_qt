#include "peripheral_pins.h"

/**
 * Map pins to gpio, peripheral, alternative function
 */
//I2C
const PinMap PinMap_I2C_SDA[] = {
    {GPIO_0,  I2C_0, ALT_0},
    {GPIO_28,  I2C_0, ALT_0},
    {GPIO_44,  I2C_0, ALT_1},

    {GPIO_2,  I2C_1, ALT_0},
    {GPIO_44,  I2C_1, ALT_2},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_I2C_SCL[] = {
    {GPIO_1,  I2C_0, ALT_0},
    {GPIO_29,  I2C_0, ALT_0},
    {GPIO_45,  I2C_0, ALT_1},

    {GPIO_3,  I2C_1, ALT_0},
    {GPIO_45,  I2C_1, ALT_2},

    {NC  ,  NC   , INPUT}
};


// UART
const PinMap PinMap_UART_TX[] = {
    {GPIO_14, UART_0, ALT_0},
    {GPIO_32, UART_0, ALT_3},
    {GPIO_36, UART_0, ALT_2},

    {GPIO_14, UART_1, ALT_5},
    {GPIO_32, UART_1, ALT_5},
    {GPIO_40, UART_1, ALT_5},

    {NC   , NC    , INPUT}
};

const PinMap PinMap_UART_RX[] = {
    {GPIO_15, UART_0, ALT_0},
    {GPIO_33, UART_0, ALT_3},
    {GPIO_37, UART_0, ALT_2},

    {GPIO_15, UART_1, ALT_5},
    {GPIO_33, UART_1, ALT_5},
    {GPIO_41, UART_1, ALT_5},

    {NC   , NC    , INPUT}
};

const PinMap PinMap_UART_CT[] = {
    {GPIO_16, UART_0, ALT_3},
    {GPIO_30, UART_0, ALT_3},
    {GPIO_39, UART_0, ALT_2},

    {GPIO_16, UART_1, ALT_5},
    {GPIO_30, UART_1, ALT_5},
    {GPIO_43, UART_1, ALT_5},

    {NC   , NC    , INPUT}
};

const PinMap PinMap_UART_RT[] = {
    {GPIO_17, UART_0, ALT_3},
    {GPIO_31, UART_0, ALT_3},
    {GPIO_39, UART_0, ALT_2},

    {GPIO_17, UART_1, ALT_5},
    {GPIO_31, UART_1, ALT_5},
    {GPIO_42, UART_1, ALT_5},

    {NC   , NC    , INPUT}
};


// SPI
const PinMap PinMap_SPI_SCLK[] = {
    {GPIO_11, SPI_0, ALT_0},
    {GPIO_39, SPI_0, ALT_0},

    {GPIO_21, SPI_1, ALT_4},

    {GPIO_42, SPI_2, ALT_4},

    {NC   , NC    , INPUT}
};

const PinMap PinMap_SPI_MOSI[] = {
    {GPIO_10, SPI_0, ALT_0},
    {GPIO_38, SPI_0, ALT_0},

    {GPIO_20, SPI_1, ALT_4},

    {GPIO_41, SPI_2, ALT_4},

    {NC   , NC    , INPUT}
};

const PinMap PinMap_SPI_MISO[] = {
    {GPIO_9, SPI_0, ALT_0},
    {GPIO_37, SPI_0, ALT_0},

    {GPIO_19, SPI_1, ALT_4},

    {GPIO_40, SPI_2, ALT_4},

    {NC   , NC    , INPUT}
};

const PinMap PinMap_SPI_SSEL[] = { // May need to slit up CE's
    {GPIO_8, SPI_0, ALT_0}, // CE0
    {GPIO_7, SPI_0, ALT_0}, // CE1
    {GPIO_36, SPI_0, ALT_0}, // CE0
    {GPIO_35, SPI_0, ALT_0}, // CE1

    {GPIO_18, SPI_1, ALT_4}, // CE0
    {GPIO_17, SPI_1, ALT_4}, // CE1
    {GPIO_16, SPI_1, ALT_4}, // CE2

    {GPIO_43, SPI_2, ALT_4}, // CE0
    {GPIO_44, SPI_2, ALT_4}, // CE1
    {GPIO_45, SPI_2, ALT_4}, // CE2

    {NC   , NC    , INPUT}
};


// PWM
const PinMap PinMap_PWM[] = {
    {GPIO_12, PWM_0 , ALT_0},
    {GPIO_18, PWM_0 , ALT_5},
    {GPIO_40, PWM_0 , ALT_0},

    {GPIO_13, PWM_1 , ALT_0},
    {GPIO_19, PWM_1 , ALT_5},
    {GPIO_41, PWM_1 , ALT_0},
    {GPIO_45, PWM_1 , ALT_0},

    {NC  ,  NC   , INPUT}
};


// General purpose clock
const PinMap PinMap_GPCLK[] = {
    {GPIO_4,  GPCLK_0 , ALT_0},
    {GPIO_32, GPCLK_0 , ALT_0},
    {GPIO_34, GPCLK_0 , ALT_0},
    {GPIO_20, GPCLK_0 , ALT_5},

    {GPIO_5,  GPCLK_1 , ALT_0},
    {GPIO_21, GPCLK_1 , ALT_5},
    {GPIO_42, GPCLK_1 , ALT_0},
    {GPIO_44, GPCLK_1 , ALT_0},

    {GPIO_6,  GPCLK_2 , ALT_0},
    {GPIO_43, GPCLK_2 , ALT_0},

    {NC  ,  NC   , INPUT}
};




// PCM
const PinMap PinMap_PCM_CLK[] = {
    {GPIO_18,  PCM_0 , ALT_0},
    {GPIO_28,  PCM_0 , ALT_2},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_PCM_FS[] = {
    {GPIO_19,  PCM_0 , ALT_0},
    {GPIO_29,  PCM_0 , ALT_2},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_PCM_DIN[] = {
    {GPIO_20,  PCM_0 , ALT_0},
    {GPIO_30,  PCM_0 , ALT_2},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_PCM_DOUT[] = {
    {GPIO_21,  PCM_0 , ALT_0},
    {GPIO_31,  PCM_0 , ALT_2},

    {NC  ,  NC   , INPUT}
};




// SDIO
const PinMap PinMap_SDIO_CLK[] = {
    {GPIO_22,  SDIO_1, ALT_3},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_SDIO_CMD[] = {
    {GPIO_23,  SDIO_1, ALT_3},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_SDIO_DATA0[] = {
    {GPIO_24,  SDIO_1, ALT_3},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_SDIO_DATA1[] = {
    {GPIO_25,  SDIO_1, ALT_3},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_SDIO_DATA2[] = {
    {GPIO_26,  SDIO_1, ALT_3},

    {NC  ,  NC   , INPUT}
};

const PinMap PinMap_SDIO_DATA3[] = {
    {GPIO_27,  SDIO_1, ALT_3},

    {NC  ,  NC   , INPUT}
};

