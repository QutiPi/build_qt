# Quti Pi C++

This project contains a Qt shared library which is a set of C++ classes that aid in using the functionality  / control of QutiPi, additional ICs and modules.

More documentation to follow as features are wrote.

## Library Aims

The main aim of the library is to help in the following areas

  * Setup and control of peripherals on the raspberry pi compute module 3
    * SPI
    * I2C
    * Serial not included (using QSerial)
    * GPIO
    * PWM
  * Setup and control of ICs and modules
    * Analogue to Digital Controllers
      * MCP3424
    * Digital to Analogue Controllers
      * AD5669
    * Pulse With Modulation Controllers
      * PCA9685A
    * Real time clocks
      * DS1307Z
    * Temperature Sensors
      * LM75
    * GPIO Expanders

## Developed by, Helped By and Supported by

This version of the QutiPi C++ was developed by Sam Mottley at the The University of Manchester's, Electronics Section (JFET Services).

However lots of credit must go to [WiringPi](http://wiringpi.com/) whom project speed up development of this project by demonstrating how X, Y, Z can be performed.

## License

Licensed under the [GNU Lesser General Public License (LGPL)](http://doc.qt.io/qt-5/lgpl.html) version 3.

All rights reserved to change at any time.