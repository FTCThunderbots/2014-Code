// background.c
// Contains code for a background processes task

#include "background.h"

void initializeRobot() {
	setMovement(0,0,0);
	nMotorEncoder[grab] = GRAB_SERVO_INIT;
}

void initializeAPI() {
	setMovement(0,0,0); //movement.c
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
