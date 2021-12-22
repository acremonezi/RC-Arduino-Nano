#ifndef JOYSTICKSREAD_H

    #define JOYSTICKSREAD_H

    // Define Global Variables
    extern int Joystick1xValue;
    extern int Joystick1yValue;
    extern int Joystick2xValue;
    extern int Joystick2yValue;
    extern int Joystick3xValue;
    extern int Joystick3yValue;
    extern int Joystick4xValue;
    extern int Joystick4yValue;

    extern byte Joystick1xValueMapped;
    extern byte Joystick1yValueMapped;
    extern byte Joystick2xValueMapped;
    extern byte Joystick2yValueMapped;
    extern byte Joystick3xValueMapped;
    extern byte Joystick3yValueMapped;
    extern byte Joystick4xValueMapped;
    extern byte Joystick4yValueMapped;

    // Read Joysticks Positions
    void joysticksRead();

    // Print Joysticks Positions
    void joysticksPrint();
    
    // Reset Joysticks Positions
    void joysticksReset();

#endif