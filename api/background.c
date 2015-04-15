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
	initSensors();
	//StartTask(matchStartListener);
	StartTask(background);
}

task background() {
	while (true) {
		//updateDebugStream(); //debug.c
		//updateDebugConsole();
		EndTimeSlice();
	}
}
