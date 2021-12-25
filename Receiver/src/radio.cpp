#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup
#include "radio.h"        // Radio Setup

#include "inputs.h"

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>


// Radio on SPI bus (CE, CSN)
RF24 radio(radioCE, radioCSN);

// Radio Address
const byte addresses[][6] = {"00001", "00002"}; // Bidiretional

// Radio Setup
void radioSetup() {

    radio.begin();
    radio.openWritingPipe(addresses[0]);        // 00001 Direction
    radio.openReadingPipe(1, addresses[1]);     // 00002 Direction
    radio.setPALevel(RF24_PA_MIN);

}

// Transmitter Variables
long Joystick1xValueReceived;
long Joystick1yValueReceived;
long Joystick2xValueReceived;
long Joystick2yValueReceived;

// Receiver Variables
bool BT1;
bool BT2;


// Create Data Structures:
// Max struct size is 32 bytes, NRF24L01 buffer limit.

  // Create Transmitter Data Structure
    struct TransmitterDataStructure {

      // Joystics
      long Joystick1xValue;
      long Joystick1yValue;
      long Joystick2xValue;
      long Joystick2yValue;

    };

  // Create a Instance of the Structure
    TransmitterDataStructure TransmitterDataPackage;

  // ---------------------------------------------

  // Create Receiver Data Structure
    struct ReceiverDataStructure {

      bool BT1;
      bool BT2;
            
    };
        
  // Create a Instance of the Structure
    ReceiverDataStructure ReceiverDataPackage;




void dataPackagesUpdate() {

    Joystick1xValueReceived = TransmitterDataPackage.Joystick1xValue;
    Joystick1yValueReceived = TransmitterDataPackage.Joystick1yValue;
    Joystick2xValueReceived = TransmitterDataPackage.Joystick2xValue;
    Joystick2yValueReceived = TransmitterDataPackage.Joystick2yValue;
   
    ReceiverDataPackage.BT1 = Button1State;
    ReceiverDataPackage.BT2 = 1;
    
}

// Print Data Packages Content:
void dataPackagesPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("Xm: ");
  Serial.print(TransmitterDataPackage.Joystick1xValue);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.Joystick1yValue);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("Xm: ");
  Serial.print(TransmitterDataPackage.Joystick2xValue);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.Joystick2yValue);

  Serial.print("Button1State: ");
  Serial.println(Button1State);


  delay(500);


}

// Radio Communication
void radioComm() {

    delay(5);
    // Set radio to RX mode
    radio.startListening();

    // Looking for incoming data
    if (radio.available()) {

        // Read Data
        radio.read(&TransmitterDataPackage, sizeof(TransmitterDataPackage));
        delay(5);

        // Set radio to TX mode 
        radio.stopListening();
        // Send Data
        radio.write(&ReceiverDataPackage, sizeof(ReceiverDataPackage));

    }
}


// Radio Test
void radioTest() {

    delay(5);
    radio.stopListening();

        const char textReceiver[] = "POng from Receiver !!!";
        radio.write(&textReceiver, sizeof(textReceiver));
        delay(5);


    delay(5);
    radio.startListening();

        if ( radio.available() ) {
            char textTransmitter[32] = "";
            radio.read(&textTransmitter, sizeof(textTransmitter));
            Serial.println(textTransmitter);
            delay(500);
        }

}