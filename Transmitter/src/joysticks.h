#ifndef JOYSTICKS_H

    #define JOYSTICKS_H

    // Define Global Variables
    extern int Joystick1xValue;
    extern int Joystick1yValue;
    extern int Joystick2xValue;
    extern int Joystick2yValue;

    extern byte Joystick1xValueMapped;
    extern byte Joystick1yValueMapped;
    extern byte Joystick2xValueMapped;
    extern byte Joystick2yValueMapped;

    // Read Joysticks Positions
    void joysticksRead();

    // Print Joysticks Positions
    void joysticksPrint();
    
    // Reset Joysticks Positions
    void joysticksReset();

#endif