    #include <Arduino.h>        // Main Arduino Library
    #include "pinMap.h"         // Pin Map Setup
    #include "pinSetup.h"       // Pin I/O Mode Setup
    
    #include "radioSetup.h"     // Radio Setup
    #include "radio.h"          // Radio Communications

    #include "joysticks.h"      // Read Joysticks Positions
    #include "dataPackages.h"

    #include <SPI.h>
    #include <RF24.h>
    #include <nRF24L01.h>


// Radio Communication
void radioComm() {
 
    delay(5);
    // Set radio to TX mode
    radio.stopListening();
    // Send Data
    radio.write(&TransmitterDataPackage, sizeof(TransmitterDataPackage));
    delay(5);

    // Set radio to RX mode
    radio.startListening();
    //Looking for incoming data
    while(!radio.available());
    // Read Data
    radio.read(&ReceiverDataPackage, sizeof(ReceiverDataPackage));

}