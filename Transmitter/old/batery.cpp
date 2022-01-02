#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup
#include "batery.h"

// Define Max Batery Voltage
float bateryVoltMax = 5;

// Define Init Variables
float bateryVoltValue = 0.0;
float voltageDividerValue = 0.0;

// Batery Voltage Measurement
void bateryVoltRead() {
    voltageDividerValue =  analogRead(bateryVolt);
    bateryVoltValue = voltageDividerValue * (bateryVoltMax / 1023.0);
}

// Print Batery Voltage Measurement
void bateryVoltReadPrint() {
  Serial.print("Voltage Divider: ");
  Serial.print(voltageDividerValue);
  Serial.print(" | Batery Voltage: ");
  Serial.println(bateryVoltValue);
  delay(500);
}