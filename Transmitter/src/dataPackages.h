#ifndef dataPackages_h

    #define dataPackages_h

    // Create Data Structures:
    // Max struct size is 32 bytes, NRF24L01 buffer limit.

    // Create Transmitter Data Structure
        struct TransmitterDataStructure {

        // Joystics
        long Joystick1xValue;
        long Joystick1yValue;
        long Joystick2xValue;
        long Joystick2yValue;

        };

    // Expose a Instance of the Structure
        extern TransmitterDataStructure TransmitterDataPackage;

    // ---------------------------------------------

    // Create Receiver Data Structure
        struct ReceiverDataStructure {

        bool BT1;
        bool BT2;
                
        };
            
    // Expose a Instance of the Structure
        extern ReceiverDataStructure ReceiverDataPackage;


    // Data Packages Data Update
    void dataPackagesUpdate();
    
    // Data Packages Data Print
    void dataPackagesPrint();

#endif