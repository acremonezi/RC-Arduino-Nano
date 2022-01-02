#ifndef joysticks_h

    #define joysticks_h

    // Define Global Variables
    extern int joystick1xValue;
    extern int joystick1yValue;
    extern int joystick2xValue;
    extern int joystick2yValue;

    // Read Joysticks Positions
    void joysticksRead();

    // Print Joysticks Positions
    void joysticksPrint();
    
    // Reset Joysticks Positions
    void joysticksReset();

#endif