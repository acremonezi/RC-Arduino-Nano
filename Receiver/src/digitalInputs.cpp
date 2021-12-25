#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup


bool Button1State = 0;

void digitalInputsRead() {

    Button1State = digitalRead(Button1);

}