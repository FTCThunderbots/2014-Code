/* sensors.c | Wrapper for the drivers in Xander's sensor driver suite
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

#include "sensors.h"

void initSensors() { //called by initializeAPI()
	initCompass();
	initIRSeeker();
}

#ifdef COMPASS
static void initCompass() {
	setCompassZero();
}

int getHeading() {
	return HTMCreadHeading(COMPASS);
}

int getRelativeHeading() {
	return HTMCreadRelativeHeading(COMPASS);
}

int setCompassZero() {
	HTMCsetTarget(COMPASS);
}
#else
static void initCompass() {}
#endif

#ifdef INFRARED
static void initIRSeeker() {
	//HTIRS2setDSPMode(INFRARED, DSP_1200);
}
int getIRpos() {
	//return HTIRS2readDCDir(INFRARED);
}
#else
static void initCompass() {}
#endif
