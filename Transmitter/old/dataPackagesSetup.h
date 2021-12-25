
#ifndef dataPackagesSetup_h

    #define dataPackagesSetup_h
    
    #include <Arduino.h>                // Main Arduino Library
    #include "pinMap.h"                 // Pin Map Setup
    #include "pinSetup.h"               // Pin I/O Mode Setup
    #include "joysticks.h"              // Joysticks Positions

    // Create Data Structures:
    // Max struct size is 32 bytes, NRF24L01 buffer limit.

        // Create Transmitter Data Structure
            struct TransmitterDataStructure {

                // Joystics
                byte Joystick1xValueMapped;
                byte Joystick1yValueMapped;
                byte Joystick2xValueMapped;
                byte Joystick2yValueMapped;

            };

        // Create a Instance of the Structure
            TransmitterDataStructure TransmitterDataPackage;


            // ---------------------------------------------


        // Create Receiver Data Structure
            struct ReceiverDataStructure {

                // null...
            
            };
        
        // Create a Instance of the Structure
            ReceiverDataStructure ReceiverDataPackage;

    // Data Packages Setup
    void dataPackagesSetup();

#endif