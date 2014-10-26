// background.c
// Contains code for a background processes task

#include "background.h"
#include "api.c"
#include "timer.c"

//#include "movement.c" //uncomment this line if it's giving compile errors for setMovement()

void initializeAPI() {
	setMovement(0,0,0);
	timeInit();
	StartTask(background);
}

task background() {
	monitorSysTimer();
	updateAllTimers();
}
