// nxt.c
// Defines code for interacting with the NXT hardware and the field

#include "nxt.h"

bool matchHasStarted = false;

int setAutoDelay() {
	nNxtExitClicks = 3;
	int delay = 0;
	eraseDisplay();
	while (nNxtButtonPressed != 3 && !matchHasStarted) {
		if (nNxtButtonPressed == 1)
			delay++;
		if (nNxtButtonPressed == 2)
			delay--;
		if (delay < 0)
			delay = 0;
		if (nNxtButtonPressed == 0)
			delay = (delay != 0) ? 0 : 15; //change to MAX_AUTO_DELAY macro
		
		nxtDisplayCenteredTextLine(0, "%2.2f second delay", delay);
		wait1Msec(300);
	}
	eraseDisplay();
	return delay;
}

task matchStartListener() {
	waitForStart();
	matchHasStarted = true;
}

void waitStartAPI() {
	while (!matchHasStarted) {}
}
