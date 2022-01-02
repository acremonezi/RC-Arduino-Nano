#ifndef RADIO_H

    #define RADIO_H

    extern int joystick1xValueReceived;
    extern int joystick1yValueReceived;
    extern int joystick2xValueReceived;
    extern int joystick2yValueReceived;

    // Radio Setup
    void radioSetup();

    // Radio Run
    void radioComm();

    // Radio Test
    void radioTest();

    void dataPackagesPrint();

    void dataPackagesUpdate();

    // Handshake Output Status on LED1
    void handshakeOutput();

#endif