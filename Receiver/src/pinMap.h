#ifndef PINMAP_H

    #define PINMAP_H
    void pinMap();


    // Define Radio on SPI bus (CE, CSN)
    // ----------------------------------------------
    #define radioCE     7       // Radio CE
    #define radioCSN    8       // Radio CSN


    // Define the Digital Outputs
    // ----------------------------------------------
    #define Led1    6           // Led 1
    #define Servo1  5           // Servo 1

    // Define the Digital Inputs
    // ----------------------------------------------
    #define Button1 4           // Button switch 1

#endif