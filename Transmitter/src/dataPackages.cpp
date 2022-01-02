#include <Arduino.h>            // Main Arduino Library
#include "pinSettings.h"        // Pin Settings Setup
#include "joysticks.h"          // Joysticks Positions

#include "dataPackages.h"       // Data Package Communication


// Create Instances of the Data Structures
TransmitterDataStructure TransmitterDataPackage;
ReceiverDataStructure ReceiverDataPackage;


// Receiver Variables
bool receiverPongValueReceived = 0;


// Update Data Packages:
void dataPackagesUpdate() {

  // Update Data to send to Receiver

    // Handshake
    TransmitterDataPackage.transmitterPingValue = 1;

    // Joystics    
    TransmitterDataPackage.joystick1xValue = joystick1xValue;
    TransmitterDataPackage.joystick1yValue = joystick1yValue;
    TransmitterDataPackage.joystick2xValue = joystick2xValue;
    TransmitterDataPackage.joystick2yValue = joystick2yValue;
    
  // Updata Data Received from Receiver

    // Handshake
    receiverPongValueReceived = ReceiverDataPackage.receiverPongValue;
    //handshakeOutput();

}


// Handshake Output Status
void handshakeOutput() {

    if (receiverPongValueReceived) {
      digitalWrite(led1, 1);
      receiverPongValueReceived = 0;
    } else {
      receiverPongValueReceived = 0;
      digitalWrite(led1, 0);
    }
  
}


// Print Data Packages Content:
void dataPackagesPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("X: ");
  Serial.print(TransmitterDataPackage.joystick1xValue);
  Serial.print(" | Y: ");
  Serial.println(TransmitterDataPackage.joystick1yValue);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("X: ");
  Serial.print(TransmitterDataPackage.joystick2xValue);
  Serial.print(" | Y: ");
  Serial.println(TransmitterDataPackage.joystick2yValue);

  Serial.print("Receiver --  ");
  Serial.print("Pong: ");
  Serial.println(ReceiverDataPackage.receiverPongValue);
  delay(1000);
} 