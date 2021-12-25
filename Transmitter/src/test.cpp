#include "test.h"         // Test Codes

// Simple Blink for LED_BUILTIN.
void testBlink() {  
   
  digitalWrite(LED1, HIGH);   
  delay(1000);                       
                 
  digitalWrite(LED1, LOW);
  delay(1000);  

}