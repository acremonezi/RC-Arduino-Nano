/*
DIY Radio Controller
By: https://github.com/acremonezi/
Date: 21/Dec/2021
*/

#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup
#include "radio.h"        // Radio Setup
#include "digitalInputs.h"

// Radio Receiver

void setup() {

  Serial.begin(9600);     // Start Serial Communication 
  pinSetup();             // Pin I/O Mode Setup
  radioSetup();           // Radio Setup
    
}

void loop() {

  //radioRun();             // Radio Start
  //radioTest();
  digitalInputsRead();
  dataPackagesUpdate();
  radioComm();
  dataPackagesPrint();

}