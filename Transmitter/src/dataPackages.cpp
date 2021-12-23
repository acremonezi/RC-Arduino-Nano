#include <Arduino.h>          // Main Arduino Library
#include "pinMap.h"           // Pin Map Setup
#include "pinSetup.h"         // Pin I/O Mode Setup
#include "joysticks.h"    // Joysticks Positions
#include "dataPackages.h"

 // Max size of this struct is 32 bytes - NRF24L01 buffer limit
    struct TransmitterData {
        // Joystics
        byte Joystick1xValueMapped;
        byte Joystick1yValueMapped;
        byte Joystick2xValueMapped;
        byte Joystick2yValueMapped;
    };
    TransmitterData TransmitterDataPackage; //Create a variable with the above structure

    struct ReceiverData {
    // null...
    };
    ReceiverData ReceiverDataPackage; //Create a variable with the above structure


void dataPackagesUpdate() {
  TransmitterDataPackage.Joystick1xValueMapped = Joystick1xValueMapped;
  TransmitterDataPackage.Joystick1yValueMapped = Joystick1yValueMapped;
  TransmitterDataPackage.Joystick2xValueMapped = Joystick2xValueMapped;
  TransmitterDataPackage.Joystick2yValueMapped = Joystick2yValueMapped;
}


void dataPackagesPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("Xm: ");
  Serial.print(TransmitterDataPackage.Joystick1xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.Joystick1yValueMapped);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("Xm: ");
  Serial.print(TransmitterDataPackage.Joystick2xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.Joystick2yValueMapped);

  delay(1000);
}