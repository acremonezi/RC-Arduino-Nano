/*
DIY Radio Controller
By: https://github.com/acremonezi/
Date: 21/Dec/2021
*/

#include <Arduino.h>          // Main Arduino Library
#include "pinMap.h"           // Pin Map Setup
#include "pinSetup.h"         // Pin I/O Mode Setup
#include "joysticks.h"        // Joysticks Info
#include "radio.h"            // Radio Setup
#include "dataPackages.h"
#include "display.h"

void setup() {

  Serial.begin(9600);         // Start Serial Communication  
  pinSetup();                 // Pin I/O Mode Setup
  radioSetup();               // Radio Setup
  displaySetup();             // Display Setup
  
}

void loop() {

  joysticksRead();            // Read Joysticks Positions
  radioRun();                 // Radio Start
  //joysticksPrint();         // Print Joysticks Positions
  dataPackagesUpdate();
  //dataPackagesPrint();
}