// background.c
// Contains code for a background processes task

#include "background.h"

void initializeAPI() {
	setMovement(0,0,0); //movement.c
	timeInit(); //timers.c
	StartTask(background);
}

task background() {
	while (true){
		monitorSysTimer(); //timers.c
		updateAllTimers(); //timers.c
		updateDebugStream(); //debug.c
	}
}
