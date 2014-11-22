// nxt.c
// Defines code for interacting with the NXT hardware and the field

#include "nxt.h"

bool matchHasStarted = false;

void waitStartAPI() {
	StartTask(trackMatchStart);
	while (!matchHasStarted) {}
}

int setAutoDelay() {
	nNxtExitClicks = 3;
	static int delay = 0;
	static int i;
	while (nNxtButtonPressed != 3 && !matchHasStarted) {
		if (nNxtButtonPressed == 1)
			delay++;
		if (nNxtButtonPressed == 2)
			delay--;
		/*
		if (delay > 15)
		delay = 0;
		if (delay < 0)
		delay = 15;
		*/
		if (nNxtButtonPressed == 0) {
			if (delay != 0)
				i = 0;
			else
				i = 15;
			delay = i;
		}
		nxtDisplayCenteredTextLine(0, "%2.2f second delay", delay);
		wait1Msec(300);
	}
	eraseDisplay();
	return delay;
}

task trackMatchStart() {
	waitForStart();
	matchHasStarted = true;
}
