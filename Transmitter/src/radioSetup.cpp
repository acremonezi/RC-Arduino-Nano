#include "radioSetup.h"

//Radio on SPI bus (CE, CSN)
RF24 radio(radioCE, radioCSN);

// Radio Address
const byte addresses[][6] = {"00001", "00002"};     // Bidiretional


// Radio Setup
void radioSetup() {
 
    radio.begin();
    radio.openWritingPipe(addresses[1]);            // 00002 Direction
    radio.openReadingPipe(1, addresses[0]);         // 00001 Direction
    radio.setPALevel(RF24_PA_MIN);

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