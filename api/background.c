// background.c
// Contains code for a background processes task

#include "background.h"

void initializeRobot() {
	halt();
	resetEncoders();
	initGrabSystem();
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
	}
}
