    #include <Arduino.h>        // Main Arduino Library
    #include "pinSettings.h"    // Pin Settings Setup
    
    #include "radioSettings.h"  // Radio Settings Setup
    #include "radio.h"          // Radio Communications

    #include "joysticks.h"      // Read Joysticks Positions
    #include "dataPackages.h"   // Data Package Communication

    #include <SPI.h>
    #include <RF24.h>
    #include <nRF24L01.h>


// Run Radio Communication
void radioCommRun() {
 
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