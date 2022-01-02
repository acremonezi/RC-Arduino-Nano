#include <Arduino.h>          // Main Arduino Library
#include "pinSettings.h"      // Pin Settings Setup
#include "joysticks.h"        // Joysticks Positions



// Arduino Nano board has 8 Analog PINs (A0 to A7) with:
// - Digital to Analog Converter (ADC) with 10 bits resolution.
// - Operating voltage of 5 Volts.
//
// 10 bit gives 2^10 = 1024 units.
// This means that it will map input voltages between 0 and 5 volts
// into integer values between 0 and 1023.
// So, as a result analog reading is limited to the resolution of (0-1023)
//
// This yields a resolution between readings of:
// 5 volts / 1024 Units --> 0.004882813 Volts/Unit (4.9mV/Unit).
//
// Calculating the current on the Joystick:
// Consider we use an 5kOhm Joystick:
// From Ohm's law: V = R.i
// i = V/R --> i = 5v/5000Ohm --> i = 0,001A (1mA)
//
// The Data type "int" was chosen because it is 16 bits, and is 
// more than enough to carry the data information.
//
// Enjoy it!



// Define Global Variables
int joystick1xValue = 512;
int joystick1yValue = 512;
int joystick2xValue = 512;
int joystick2yValue = 512;



// Read Joysticks Positions
void joysticksRead() {
  // Yaw (Left and Right)
  joystick1xValue = analogRead(joystick1x);
  // Thottle (Up and Down)
  joystick1yValue = analogRead(joystick1y);
  // Roll (Left and Rigt)
  joystick2xValue = analogRead(joystick2x);
  // Pitch (Down and Up)
  joystick2yValue = analogRead(joystick2y);
}



// Reset Joysticks Positions
void joysticksReset() {
  joystick1xValue = 512;
  joystick1yValue = 512;
  joystick2xValue = 512;
  joystick2yValue = 512;
}



void joysticksPrint() {

  Serial.print("J1 -- Yaw  | Thottle -- ");
  Serial.print("X: ");
  Serial.print(joystick1xValue);
  Serial.print(" | Y: ");
  Serial.print(joystick1yValue);

  Serial.print(" -- Xm: ");
  Serial.print(joystick1xValue);
  Serial.print(" | Ym: ");
  Serial.println(joystick1yValue);

  Serial.print("J2 -- Roll | Pitch   -- ");
  Serial.print("X: ");
  Serial.print(joystick2xValue);
  Serial.print(" | Y: ");
  Serial.print(joystick2yValue);

  Serial.print(" -- Xm: ");
  Serial.print(joystick2xValue);
  Serial.print(" | Ym: ");
  Serial.println(joystick2yValue);

  delay(500);

}