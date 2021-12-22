#include <Arduino.h>      // Main Arduino Library
#include "pinMap.h"       // Pin Map Setup
#include "pinSetup.h"     // Pin I/O Mode Setup
#include "radio.h"        // Radio Setup

#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <Servo.h>


// Radio on SPI bus (CE, CSN)
RF24 radio(radioCE, radioCSN);

// Radio Address
const byte addresses[][6] = {"00001", "00002"};

// Servo
Servo myServo;
boolean buttonState = 0;


// Radio Initialization
void radioInit() {
  // null....
}


// Radio Setup
void radioSetup() {

    myServo.attach(Servo1);

    Serial.begin(9600);
    radio.begin();
    radio.openWritingPipe(addresses[0]);    // 00001
    radio.openReadingPipe(1, addresses[1]); // 00002
    radio.setPALevel(RF24_PA_MIN);

}


// Radio Run
void radioRun(){

    delay(100);
    radio.startListening();
    
    if ( radio.available()) {
        while (radio.available()) {
            int angleV = 0;
            radio.read(&angleV, sizeof(angleV));
            myServo.write(angleV);
            Serial.println(angleV);
            }

        delay(100);
        radio.stopListening();
        
        buttonState = digitalRead(Button1);
        radio.write(&buttonState, sizeof(buttonState));
        Serial.println(buttonState);
    }
}


// Radio Test
void radioTest() {

    if (radio.available()) {
        char text[32] = "";
        radio.read(&text, sizeof(text));
        Serial.println(text);
    }

}