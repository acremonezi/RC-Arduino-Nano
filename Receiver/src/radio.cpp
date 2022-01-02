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
bool transmitterPingValueReceived;
int joystick1xValueReceived;
int joystick1yValueReceived;
int joystick2xValueReceived;
int joystick2yValueReceived;


// Receiver Variables
bool receiverPongValue;


// Create Data Structures:
// Max struct size is 32 bytes, NRF24L01 buffer limit.

  // Create Transmitter Data Structure
    struct TransmitterDataStructure {

        // Handshake
        bool transmitterPingValue;

        // Joystics
        int joystick1xValue;
        int joystick1yValue;
        int joystick2xValue;
        int joystick2yValue;

    };

  // Create a Instance of the Structure
    TransmitterDataStructure TransmitterDataPackage;

  // ---------------------------------------------

  // Create Receiver Data Structure
    struct ReceiverDataStructure {

        // Handshake
        bool receiverPongValue;
            
    };
        
  // Create a Instance of the Structure
    ReceiverDataStructure ReceiverDataPackage;




void dataPackagesUpdate() {

  // Update Data Received from Transmitter

    // Joystics    
    joystick1xValueReceived = TransmitterDataPackage.joystick1xValue;
    joystick1yValueReceived = TransmitterDataPackage.joystick1yValue;
    joystick2xValueReceived = TransmitterDataPackage.joystick2xValue;
    joystick2yValueReceived = TransmitterDataPackage.joystick2yValue;
 
    // Handshake
    transmitterPingValueReceived = TransmitterDataPackage.transmitterPingValue;
    //handshakeOutput();

  // Update Data to send to Transmitter
  
    // Handshake
    ReceiverDataPackage.receiverPongValue = 1;

}


// Handshake Output Status on LED1
void handshakeOutput() {
    // Output Handshake Status
    if (transmitterPingValueReceived) {
      digitalWrite(led1, 1);
      transmitterPingValueReceived = 0;
    } else {
      transmitterPingValueReceived = 0;
      digitalWrite(led1, 0);
    }
}


// Print Data Packages Content:
void dataPackagesPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("Xm: ");
  Serial.print(TransmitterDataPackage.joystick1xValue);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.joystick1yValue);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("Xm: ");
  Serial.print(TransmitterDataPackage.joystick2xValue);
  Serial.print(" | Ym: ");
  Serial.println(TransmitterDataPackage.joystick2yValue);

  Serial.print("Transmitter --  ");
  Serial.print("Ping: ");
  Serial.println(TransmitterDataPackage.transmitterPingValue);


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