#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup
#include "radio.h"

// Arduino Nano
// Default PWM frequency:
// for: D3, D9, D10, and D11: 490.20 Hz (The DEFAULT)
// for D5 & D6: 976.56 Hz (The DEFAULT)



void outputUpdate() {

    int joystick1yValueReceivedMaped = map(joystick1yValueReceived, -512, 512, 0, 255);

    //if ( joystick1yValueReceivedMaped > -5 || joystick1yValueReceivedMaped < 5 ) {
    //    joystick1yValueReceivedMaped = 0;
    //}

    analogWrite(PWM1, joystick1yValueReceivedMaped);
    analogWrite(PWM2, joystick1yValueReceivedMaped);

}