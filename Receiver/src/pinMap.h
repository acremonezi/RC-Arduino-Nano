#ifndef PINMAP_H

    #define PINMAP_H
    void pinMap();


    // Define Radio on SPI bus (CE, CSN)
    // ----------------------------------------------
    #define radioCE     7       // Radio CE
    #define radioCSN    8       // Radio CSN

    // Define the Analog Inputs
    // ----------------------------------------------
    #define bateryVolt  A0       // Batery Voltage

    // Define the Digital Outputs
    // ----------------------------------------------
    #define led1    10           // Led 1
    #define Servo1  5           // Servo 1

    // Define the Digital Outputs (PWM)
    // ----------------------------------------------
    // Arduino Nano Default PWM frequency:
    // for: D3, D9, D10, and D11: 490.20 Hz (The DEFAULT)
    // for D5 & D6: 976.56 Hz (The DEFAULT)

    #define PWM1    6           // Servo 1
    #define PWM2    9           // Servo 1

    // Define the Digital Inputs
    // ----------------------------------------------
    #define Button1 3           // Button switch 1

#endif