#include <Arduino.h>          // Main Arduino Library
#include "pinMap.h"           // Pin Map Setup
#include "pinSetup.h"         // Pin I/O Mode Setup
#include "joysticks.h"    // Joysticks Positions

    // Define Global Variables
    int Joystick1xValue = 0;
    int Joystick1yValue = 0;
    int Joystick2xValue = 0;
    int Joystick2yValue = 0;
    int Joystick3xValue = 0;
    int Joystick3yValue = 0;
    int Joystick4xValue = 0;
    int Joystick4yValue = 0;

    byte Joystick1xValueMapped = 127;
    byte Joystick1yValueMapped = 127;
    byte Joystick2xValueMapped = 127;
    byte Joystick2yValueMapped = 127;
    byte Joystick3xValueMapped = 127;
    byte Joystick3yValueMapped = 127;
    byte Joystick4xValueMapped = 127;
    byte Joystick4yValueMapped = 127;

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
  
  Joystick3xValue = analogRead(Joystick3x);
  Joystick3yValue = analogRead(Joystick3y);
  Joystick4xValue = analogRead(Joystick4x);
  Joystick4yValue = analogRead(Joystick4y);


  // Yaw (Left and Right)
  Joystick1xValueMapped = map(Joystick1xValue, 0, 1024, 0, 255);
  // Thottle (Up and Down)
  Joystick1yValueMapped = map(Joystick1yValue, 0, 1024, 0, 255);
  // Roll (Left and Rigt)
  Joystick2xValueMapped = map(Joystick2xValue, 0, 1024, 0, 255);
  // Pitch (Down and Up)
  Joystick2yValueMapped = map(Joystick2yValue, 0, 1024, 0, 255);
  
  Joystick3xValueMapped = map(Joystick3xValue, 0, 1024, 0, 255);
  Joystick3yValueMapped = map(Joystick3yValue, 0, 1024, 0, 255);
  Joystick4xValueMapped = map(Joystick4xValue, 0, 1024, 0, 255);
  Joystick4yValueMapped = map(Joystick4yValue, 0, 1024, 0, 255);

}

void joysticksReset() {

  Joystick1xValue = 127;
  Joystick1yValue = 127;
  Joystick2xValue = 127;
  Joystick2yValue = 127;
  Joystick3xValue = 127;
  Joystick3yValue = 127;
  Joystick4xValue = 127;
  Joystick4yValue = 127;

}


void joysticksPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("X: ");
  Serial.print(Joystick1xValue);
  Serial.print(" | Y: ");
  Serial.print(Joystick1yValue);

  Serial.print(" -- Xm: ");
  Serial.print(Joystick1xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(Joystick1yValueMapped);


  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("X: ");
  Serial.print(Joystick2xValue);
  Serial.print(" | Y: ");
  Serial.print(Joystick2yValue);

  Serial.print(" -- Xm: ");
  Serial.print(Joystick2xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(Joystick2yValueMapped);

  Serial.println("-----------------------------------------");

  Serial.print("J3 ---------------------");
  Serial.print("X: ");
  Serial.print(Joystick3xValue);
  Serial.print(" | Y: ");
  Serial.print(Joystick3yValue);

  Serial.print(" -- Xm: ");
  Serial.print(Joystick3xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(Joystick3yValueMapped);

  Serial.print("J4 ---------------------");
  Serial.print("X: ");
  Serial.print(Joystick4xValue);
  Serial.print(" | Y: ");
  Serial.print(Joystick4yValue);

  Serial.print(" -- Xm: ");
  Serial.print(Joystick4xValueMapped);
  Serial.print(" | Ym: ");
  Serial.println(Joystick4yValueMapped);

  delay(1000);

}