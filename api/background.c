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
	StartTask(trackMatchStart);
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

void referenceTasks() {
	return;
	// This is all dead code
	// It only exists to avoid 'unrefrenced' warnings
	StartTask(grabGoalTask);
	StartTask(releaseGoalTask);
	StartTask(toggleGrabTask);
}
