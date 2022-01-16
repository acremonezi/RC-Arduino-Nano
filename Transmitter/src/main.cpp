/*
Welcome!
This is a project of:
A powerful and fully customizable DIY Open Source Arduino Radio Controller
(Transmitter and Receiver) powered by Arduino Nano microcontroller.

This is complete solution with Electronics, PCB, Software and 3D Printed Case.
All you need is basic knowledge and willpower.
Please, Enjoy it and have fun!

Sources at: https://github.com/acremonezi/RC-Arduino-Nano/
Created at: 12th of December, 2021. (In Brazil)
Author: Alcides Cremonezi
*/

#include "main.h"             // Load Libraries


// Radio Transmitter


void setup() {

  // Execute only If DEBUG is enabled in pinSettings.h
  #ifdef DEBUG
    Serial.begin(9600);       // Start Serial Communication
  #endif 

  pinSettings();              // Pin Settings Setup
  radioSettings();            // Radio Settings Setup

}


void loop() {

  // Main Functions
    joysticksRead();            // Read Joysticks Positions
    dataPackagesUpdate();       // Send Input Data to Data Packages
    radioCommRun();             // Run Radio Communication

  // Execute only If DEBUG is enabled in pinSettings.h
  #ifdef DEBUG
    //dataPackagesPrint();      // Print Data Packages Data
    //joysticksPrint();         // Print Joysticks Data
    //radioTest();              // Test Radio Communications
    //joysticksPrint();         // Print Joysticks Positions
  #endif 

}