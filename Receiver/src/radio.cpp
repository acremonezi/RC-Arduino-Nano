#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup
#include "radio.h"        // Radio Setup

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
//#include <Servo.h>


// Radio on SPI bus (CE, CSN)
RF24 radio(radioCE, radioCSN);

// Radio Address
const byte addresses[][6] = {"00001", "00002"}; // Bidiretional

// Servo
//Servo myServo;
//boolean buttonState = 0;


// Radio Setup
void radioSetup() {

    //myServo.attach(Servo1);

    radio.begin();
    radio.openWritingPipe(addresses[0]);    // 00001
    radio.openReadingPipe(1, addresses[1]); // 00002
    radio.setPALevel(RF24_PA_MIN);

}


// Radio Run
void radioRun(){

    delay(5);
    radio.startListening();
    
    //if ( radio.available()) {
        //while (radio.available()) {
            //int angleV = 0;
            //radio.read(&angleV, sizeof(angleV));
            //myServo.write(angleV);
            //Serial.println(angleV);
            //}

    delay(5);
    radio.stopListening();
        
        //buttonState = digitalRead(Button1);
        //radio.write(&buttonState, sizeof(buttonState));
        //Serial.println(buttonState);
    //}
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