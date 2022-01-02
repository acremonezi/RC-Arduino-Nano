#ifndef pinSettings_h

    #define pinSettings_h
    
    // Define Radio on SPI bus (CE, CSN)
    // ----------------------------------------------
    #define radioCE         7       // Radio CE
    #define radioCSN        6       // Radio CSN

    // Define the Analog Inputs
    // ----------------------------------------------
    #define joystick1x      A0       // Joystick 1 eixo X
    #define joystick1y      A1       // Joystick 1 eixo Y
    #define joystick2x      A2       // Joystick 2 eixo X
    #define joystick2y      A3       // Joystick 2 eixo Y

    // Define the Digital Outputs
    // ----------------------------------------------
    #define led1            2       // LED 1

    // Pin Settings Setup
    void pinSettings();

#endif