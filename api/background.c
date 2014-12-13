// background.c
// Contains code for a background processes task

#include "background.h"

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

void initializeRobot() {
	halt();
	resetEncoders();
	initGrabSystem();
	initBackboardServo();
}

void initializeAPI() {
	timeInit(); //timers.c
	initDebugConsole();
	StartTask(background);
}

task background() {
	while (true){
		monitorSysTimer(); //timers.c
		updateAllTimers(); //timers.c
		updateDebugStream(); //debug.c
    	updateDebugConsole();
		EndTimeSlice();
	}
}

static void fixUnreferencedWarnings() {
	return; // this is all dead code to confuse the compiler
	int n = SWEEP_MOTOR_SPEED;
	n += SWEEP_MOTOR_SLOW_SPEED;
	n += CONVEYOR_MOTOR_SPEED;
	n += CONVEYOR_MOTOR_SLOW_SPEED;

	StartTask(grabGoalTask);
	StartTask(releaseGoalTask);
	StartTask(toggleGrabTask);
	StartTask(engageBackboardTask);
	StartTask(disengageBackboardTask);
	StartTask(toggleBackboardTask);
}
