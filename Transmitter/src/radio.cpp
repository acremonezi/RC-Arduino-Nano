#include <Arduino.h>        // Main Arduino Library
#include "pinMap.h"         // Pin Map Setup
#include "pinSetup.h"       // Pin I/O Mode Setup
#include "radio.h"          // Radio Setup
//#include "joysticks.h"  // Read Joysticks Positions
#include "dataPackages.h"

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

// Radio on SPI bus (CE, CSN)
RF24 radio(radioCE, radioCSN);


// Radio Address
const byte addresses[][6] = {"00001", "00002"};



// Radio Initialization
void radioInit() {
  // null....
}

// Radio Setup
void radioSetup() {

    //Serial.begin(9600);         // Start Serial Communication  
    radio.begin();
    radio.openWritingPipe(addresses[1]);    // 00002
    radio.openReadingPipe(1, addresses[0]); // 00001
    radio.setPALevel(RF24_PA_MIN);

}

// Radio Run
void radioRun() {
  
  // Send Data
  delay(5);
  radio.stopListening();
  //radio.write(&TransmitterDataPackage, sizeof(TransmitterDataPackage));
  //Serial.print(TransmitterDataPackage.Joystick1yValue);
  //Serial.println(TransmitterDataPackage.Joystick2xValue);
  //delay(1000);

  // Receive Data
  delay(5);
  radio.startListening();
  //while (!radio.available());
  //radio.read(&ReceiverDataPackage, sizeof(ReceiverDataPackage));
  

}


// Radio Test
void radioTest() {

    const char text[] = "Hello World !!!";
    radio.write(&text, sizeof(text));
    delay(1000);
    //Serial.println(text);

}