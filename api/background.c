// background.c
// Contains code for a background processes task

#include "api.h"
#include "timer.c"

void initializeAPI() {
	timeInit();
}

task background() {
	monitorSysTimer();
	updateAllTimers();
}
