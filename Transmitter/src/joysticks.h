#ifndef joysticks_h

    #define joysticks_h

    // Define Global Variables
    extern long Joystick1xValue;
    extern long Joystick1yValue;
    extern long Joystick2xValue;
    extern long Joystick2yValue;

    // Read Joysticks Positions
    void joysticksRead();

    // Print Joysticks Positions
    void joysticksPrint();
    
    // Reset Joysticks Positions
    void joysticksReset();

#endif