#include <Arduino.h>                // Main Arduino Library
#include "pinSettings.h"            // Pin Settings Setup


// Pin I/O Mode Setup
void pinSettings() {

    // Define the Analog Inputs
    // ----------------------------------------------
    pinMode(joystick1x, INPUT);     // Joystick 1 eixo X
    pinMode(joystick1y, INPUT);     // Joystick 1 eixo Y
    pinMode(joystick2x, INPUT);     // Joystick 2 eixo X
    pinMode(joystick2y, INPUT);     // Joystick 2 eixo Y
  
    // Define the Digital Outputs
    // ----------------------------------------------
    pinMode(led1, OUTPUT);          // LED Radio Communication Stablished Successfully

}