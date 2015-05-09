/* nxt.c | Common functions for interfacing with the physical NXT brick
 * Copyright (C) 2015 Thunderbots-5604
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

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
