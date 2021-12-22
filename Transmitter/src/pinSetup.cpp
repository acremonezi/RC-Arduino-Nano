#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup

// Pin I/O Mode Setup

void pinSetup() {

    pinMode(Joystick1x, INPUT);
    pinMode(Joystick1y, INPUT);
    pinMode(Joystick2x, INPUT);
    pinMode(Joystick2y, INPUT);
    pinMode(Joystick3x, INPUT);
    pinMode(Joystick3y, INPUT);
    pinMode(Joystick4x, INPUT);
    pinMode(Joystick4y, INPUT);

    pinMode(Toggle1, INPUT_PULLUP);
  
    pinMode(Button1, INPUT_PULLUP);

    pinMode(Led1, OUTPUT);

}