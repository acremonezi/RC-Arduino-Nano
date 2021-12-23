#include <Arduino.h>        // Main Arduino Library
#include "pinMap.h"         // Pin Map Setup
#include "pinSetup.h"       // Pin I/O Mode Setup
#include "radio.h"          // Radio Setup
#include "joysticks.h"      // Read Joysticks Positions
#include "dataPackages.h"

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
    radio.openWritingPipe(addresses[1]);    // 00002 Bidiretional
    radio.openReadingPipe(1, addresses[0]); // 00001 Bidiretional
    radio.setPALevel(RF24_PA_MIN);

}

// Radio Run
void radioRun() {
  
  // Send Data
  delay(5);
  radio.stopListening();

      char textTest2[] = "Test OK!";
      const char textTransmitter[] = textTest2;
      
      ///radio.write(&textTransmitter, sizeof(textTransmitter));
      ///delay(5);

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

    delay(5);
    radio.stopListening();

      const char textTransmitter[] = "PIng from Transmitter !!!";
      radio.write(&textTransmitter, sizeof(textTransmitter));
      delay(5);


    delay(5);
    radio.startListening();

      if ( radio.available() ) {
        char textReceiver[32] = "";
        radio.read(&textReceiver, sizeof(textReceiver));
        Serial.println(textReceiver);
        delay(500);
      }

}