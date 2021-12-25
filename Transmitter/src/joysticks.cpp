#include <Arduino.h>          // Main Arduino Library
#include "pinMap.h"           // Pin Map Setup
#include "pinSetup.h"         // Pin I/O Mode Setup
#include "joysticks.h"        // Joysticks Positions

// Define Global Variables
long Joystick1xValue = 512;
long Joystick1yValue = 512;
long Joystick2xValue = 512;
long Joystick2yValue = 512;

// Read Joysticks Positions
void joysticksRead() {

  // Yaw (Left and Right)
  Joystick1xValue = analogRead(Joystick1x);
  // Thottle (Up and Down)
  Joystick1yValue = analogRead(Joystick1y);
  // Roll (Left and Rigt)
  Joystick2xValue = analogRead(Joystick2x);
  // Pitch (Down and Up)
  Joystick2yValue = analogRead(Joystick2y);

}

// Reset Joysticks Positions
void joysticksReset() {

  Joystick1xValue = 512;
  Joystick1yValue = 512;
  Joystick2xValue = 512;
  Joystick2yValue = 512;

}


void joysticksPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("X: ");
  Serial.print(Joystick1xValue);
  Serial.print(" | Y: ");
  Serial.print(Joystick1yValue);

  Serial.print(" -- Xm: ");
  Serial.print(Joystick1xValue);
  Serial.print(" | Ym: ");
  Serial.println(Joystick1yValue);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("X: ");
  Serial.print(Joystick2xValue);
  Serial.print(" | Y: ");
  Serial.print(Joystick2yValue);

  Serial.print(" -- Xm: ");
  Serial.print(Joystick2xValue);
  Serial.print(" | Ym: ");
  Serial.println(Joystick2yValue);

  delay(500);

}