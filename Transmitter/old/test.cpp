#include "test.h"         // Test Codes

// Simple Blink for LED.
void testBlink() {  
   
  digitalWrite(led1, HIGH);   
  delay(1000);                       
                 
  digitalWrite(led1, LOW);
  delay(1000);  

}