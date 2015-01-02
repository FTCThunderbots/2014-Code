// background.c
// Contains code for a background processes task

#include "background.h"

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

void initializeRobot() {
        halt();
        resetEncoders();
        nMotorEncoder[grab] = 1;
        nMotorEncoder[backboard] = 1;
}

void initializeAPI() {
        initDebugConsole();
		initSensors();
        StartTask(background);
}

task background() {
        while (true) {
                updateDebugStream(); //debug.c
                updateDebugConsole();
                EndTimeSlice();
        }
}

static void suppressUnreferencedWarnings(int a) {
        a = BACKBOARD_MOTOR_UP_POS;
        a = BACKBOARD_MOTOR_DOWN_POS;
		a = DEFAULT_MOVE_POWER;
        StartTask(matchStartListener);
}
