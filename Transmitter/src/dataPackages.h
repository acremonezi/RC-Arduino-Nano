#ifndef dataPackages_h

    #define dataPackages_h

    // Create Data Structures:
    // Max struct size is 32 bytes, NRF24L01 buffer limit.

    // Create Transmitter Data Structure
        struct TransmitterDataStructure {

        // Handshake
        bool transmitterPingValue;

        // Joystics
        int joystick1xValue;
        int joystick1yValue;
        int joystick2xValue;
        int joystick2yValue;

        };

    // Expose a Instance of the Structure
        extern TransmitterDataStructure TransmitterDataPackage;


    // ---------------------------------------------


    // Create Receiver Data Structure
        struct ReceiverDataStructure {
        
        // Handshake
        bool receiverPongValue;
                
        };
            
    // Expose a Instance of the Structure
        extern ReceiverDataStructure ReceiverDataPackage;


    // Data Packages Data Update
    void dataPackagesUpdate();
    
    // Data Packages Data Print
    void dataPackagesPrint();
    
    // Handshake Output Status
    void handshakeOutput();

#endif