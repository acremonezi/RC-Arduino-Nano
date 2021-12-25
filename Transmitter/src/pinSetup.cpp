
#include "pinSetup.h"

// Pin I/O Mode Setup
void pinSetup() {

    // Define the Analog Inputs
    // ----------------------------------------------
    pinMode(Joystick1x, INPUT);                 // Joystick 1 eixo X
    pinMode(Joystick1y, INPUT);                 // Joystick 1 eixo Y
    pinMode(Joystick2x, INPUT);                 // Joystick 2 eixo X
    pinMode(Joystick2y, INPUT);                 // Joystick 2 eixo Y

    // Define the Digital Inputs
    // ----------------------------------------------
    //pinMode(Joystick1Button, INPUT_PULLUP);     // Joystick1 Button
    //pinMode(Joystick1Button, INPUT_PULLUP);     // Joystick2 Button
  
    // Define the Digital Outputs
    // ----------------------------------------------
    pinMode(LED1, OUTPUT);                       // LED 1

}