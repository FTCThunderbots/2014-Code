// background.c
// Contains code for a background processes task

#include "background.h"

void initializeAPI() {
	setMovement(0,0,0);
	timeInit();
	StartTask(background);
}

task background() {
	monitorSysTimer();
	updateAllTimers();
}
