#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup

// Pin I/O Mode Setup

void pinSetup() {

    // Define the Analog Inputs
    // ----------------------------------------------
    pinMode(bateryVolt, INPUT);                 // Batery Voltage

    // Define the Digital Inputs
    // ----------------------------------------------
    pinMode(Button1, INPUT_PULLUP);
    pinMode(led1, OUTPUT);
    pinMode(Servo1, OUTPUT);

    // Arduino Nano Default PWM frequency:
    // for: D3, D9, D10, and D11: 490.20 Hz (The DEFAULT)
    // for D5 & D6: 976.56 Hz (The DEFAULT)

    pinMode(PWM1, OUTPUT);
    pinMode(PWM2, OUTPUT);
    
}