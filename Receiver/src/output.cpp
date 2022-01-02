#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup
#include "radio.h"

// Arduino Nano
// Default PWM frequency:
// for: D3, D9, D10, and D11: 490.20 Hz (The DEFAULT)
// for D5 & D6: 976.56 Hz (The DEFAULT)



void outputUpdate() {

    analogWrite(PWM1, map(joystick1yValueReceived, 0, 1023, 0, 255));
    analogWrite(PWM2, map(joystick1yValueReceived, 0, 1023, 0, 255));

}