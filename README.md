# QutiPi C++

QutiPi C++ is an opensource embedded framework to aid in creating programs on embedded platforms.
The main goal is to allow easy control of IC peritherals and communication with remote on board ICs.

## Why?

There are many different C++ libraries out there for the Pi specifically however the over all architecture makes them difficult to understand and expand.

The architecture of QutiPi-C++ allows addtional ICs and boards to be intergrated with ease while each implimenation is seperate from each other.

Each processir and board implimenation must apply to a stand HAL interface which allows standard C++ wrappers / drivers.

The end user will use the C++ drivers allowing them to have a standard interface for all processors and boards.

More details to follow.

## Processor Support

Current embedded proccessors supported:

  * Raspberry Pi CM3


## External IC Support

List of currently support external ICs

  * MCP3424

## Goals

The main goals for this library over the next 6 months is to impliment

  * Setup and control of all peripherals on the raspberry pi compute module 3
    * SPI
    * Delay (completed)
    * I2C (completed)
    * Time (completed)
    * DMA
    * GPCLK (semi-completed)
    * GPIO (completed)
    * Interrupts (completed)
    * PWM
  * Standard driver to controller the IC using C++ classes
    * PwmOut
    * HwClock
    * Timer
    * DigitalIn (completed)
    * DigitalOut (completed)
    * Interrupt
    * SPI
    * I2C (completed)
  * Platform helps in application development using C++ classes
    * Wait
    * Time
    * NonCopyable
    * CircularBuffer
    * CallBack (completed[Modifed mbed Implimenation])
  * Setup and control of ICs and modules
    * Analogue to Digital Controllers
      * MCP3424 (completed)
    * Digital to Analogue Controllers
      * AD5669
    * Pulse With Modulation Controllers
      * PCA9685A
    * Real time clocks
      * DS1307Z
    * Temperature Sensors
      * LM75
    * GPIO Expanders

## Coding Standards

This project is no too strict on coding standard however i encourage you to have a scan through http://www.possibility.com/Cpp/CppCodingStandard.html

Noting the main difference betwen sytax for C vs C++, for example for function / method names

  * C: gpio_init()
  * C++: gpioInit()

## Developed by, Helped By and Supported by

This version of the QutiPi C++ was developed by Sam Mottley at the The University of Manchester's, Electronics Section (JFET Services).

### Suggestions

This library does its best to minic the ARMmbed project to reduce learn curve.

If you after libraries with more functionality but less structure check out the below. They were also helpful in the creation of this library.
  * [WiringPi](http://wiringpi.com/)
  * [PiGPIO](http://abyz.me.uk/rpi/pigpio/)


## License

Licensed under the [GNU Lesser General Public License (LGPL)](http://doc.qt.io/qt-5/lgpl.html) version 3.

All rights reserved to change at any time.
