// background.c
// Contains code for a background processes task

#include "background.h"

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

void initializeRobot() {
        halt();
        resetEncoders();
}

void initializeAPI() {
        initDebugConsole();
        StartTask(background);
}

task background() {
        while (true) {
                updateDebugStream(); //debug.c
                updateDebugConsole();
                EndTimeSlice();
        }
}

static void suppressUnreferencedWarnings() {
        int a = BACKBOARD_MOTOR_UP_POS;
        int b = BACKBOARD_MOTOR_DOWN_POS;
        a += b;
        b += a;
        StartTask(matchStartListener);
}
