// background.c
// Contains code for a background processes task

#include "background.h"

void initializeAPI() {
	setMovement(0,0,0); //implemented in movement.c
	timeInit(); //imp. timers.c
	StartTask(background);
}

task background() {
	monitorSysTimer(); //imp. timers.c
	updateAllTimers(); //imp. timers.c
}
