#include <Arduino.h>            // Main Arduino Library
#include "pinMap.h"             // Pin Map Setup
#include "pinSetup.h"           // Pin I/O Mode Setup
#include "joysticks.h"          // Joysticks Positions

#include "dataPackagesSetup.h"
#include "dataPackages.h"


// Update Data Packages:
void dataPackagesUpdate() {
  TransmitterDataPackage.Joystick1xValueMapped = Joystick1xValueMapped;
  TransmitterDataPackage.Joystick1yValueMapped = Joystick1yValueMapped;
  TransmitterDataPackage.Joystick2xValueMapped = Joystick2xValueMapped;
  TransmitterDataPackage.Joystick2yValueMapped = Joystick2yValueMapped;
}


// Print Data Packages Content:
void dataPackagesPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("Xm: ");
  Serial.print("%d", TransmitterDataPackage.Joystick1xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.Joystick1yValueMapped);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("Xm: ");
  Serial.print(TransmitterDataPackage.Joystick2xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.Joystick2yValueMapped);

  delay(1000);
} 