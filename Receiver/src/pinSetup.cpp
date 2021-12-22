#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup

// Pin I/O Mode Setup

void pinSetup() {

    pinMode(Button1, INPUT_PULLUP);

    pinMode(Led1, OUTPUT);
    pinMode(Servo1, OUTPUT);

}