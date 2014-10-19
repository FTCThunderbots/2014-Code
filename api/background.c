// background.c
// Contains code for a background processes task

#include "api.h"

void initializeAPI() {
	timeInit();
}

task background() {
	monitorSysTimer();
	updateAllTimers();
}