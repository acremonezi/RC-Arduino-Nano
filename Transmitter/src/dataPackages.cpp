#include <Arduino.h>            // Main Arduino Library
#include "pinMap.h"             // Pin Map Setup
#include "pinSetup.h"           // Pin I/O Mode Setup
#include "joysticks.h"          // Joysticks Positions

#include "dataPackages.h"

// Create Instances of the Data Structures
TransmitterDataStructure TransmitterDataPackage;
ReceiverDataStructure ReceiverDataPackage;


// Update Data Packages:
void dataPackagesUpdate() {
  TransmitterDataPackage.Joystick1xValue = long(Joystick1xValue);
  TransmitterDataPackage.Joystick1yValue = long(Joystick1yValue);
  TransmitterDataPackage.Joystick2xValue = long(Joystick2xValue);
  TransmitterDataPackage.Joystick2yValue = long(Joystick2yValue);
}



// Print Data Packages Content:
void dataPackagesPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("X: ");
  Serial.print(TransmitterDataPackage.Joystick1xValue);
  Serial.print(" | Y: ");
  Serial.println(TransmitterDataPackage.Joystick1yValue);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("X: ");
  Serial.print(TransmitterDataPackage.Joystick2xValue);
  Serial.print(" | Y: ");
  Serial.println(TransmitterDataPackage.Joystick2yValue);

  Serial.print("Receiver --  ");
  Serial.print("BT1: ");
  Serial.print(ReceiverDataPackage.BT1);
  Serial.print(" | BT2: ");
  Serial.println(ReceiverDataPackage.BT2);
  delay(1000);
} 