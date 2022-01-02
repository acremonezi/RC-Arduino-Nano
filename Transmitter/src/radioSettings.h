#ifndef radioSetup_h

    #define radioSetup_h

    // The Libraries was included into this radioSetup.h
    // header file, instead of the radioSetup.cpp file
    // because it was the only way I found to extern the
    // "RF24 radio" instance of the Library RF24 bellow.

    #include <Arduino.h>            // Main Arduino Library
    #include "pinSettings.h"        // Pin Settings Setup
    
    #include <SPI.h>
    #include <RF24.h>
    #include <nRF24L01.h>

    // Radio on SPI bus (CE, CSN)
    extern RF24 radio;

    // Radio Address
    extern const byte addresses[][6];

    // Radio Settings Setup
    void radioSettings();

    // Radio Test
    void radioTest();

#endif