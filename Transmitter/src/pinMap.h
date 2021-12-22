#ifndef PINMAP_H

    #define PINMAP_H
    void pinMap();


    // Define Radio on SPI bus (CE, CSN)
    // ----------------------------------------------
    #define radioCE     7       // Radio CE
    #define radioCSN    8       // Radio CSN

    // Define 128x64 I2C Oled Display 
    // ----------------------------------------------
    //#define displaySDA      A4      // SDA
    //#define displaySCL      A5      // SCL

    // Define the Analog Inputs
    // ----------------------------------------------
    #define Joystick1x A0       // Joystick 1 eixo X
    #define Joystick1y A1       // Joystick 1 eixo Y
    #define Joystick2x A2       // Joystick 2 eixo X
    #define Joystick2y A3       // Joystick 2 eixo Y
    #define Joystick3x A6       // Joystick 3 eixo X
    #define Joystick3y A7       // Joystick 3 eixo Y
    #define Joystick4x A6       // Joystick 4 eixo X
    #define Joystick4y A7       // Joystick 4 eixo Y


    // Define the Digital Inputs
    // ----------------------------------------------
    #define Toggle1 6           // Toggle switch 1
    
    #define Button1 5           // Button switch 1

    // Define the Digital Outputs
    // ----------------------------------------------
    #define Led1 4              // Led 1

#endif