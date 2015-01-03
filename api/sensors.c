// sensors.c
// Contains methods for getting the values of sensors on the robot

#include "sensors.h"

int initialCompassReading = 0;

int getCompassReading() {
    return SensorValue[compass];
}

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
	HTIRS2setDSPMode(INFRARED, DSP_1200);
}
int getIRpos() {
	return HTIRS2readDCDir(INFRARED);
}
#else
static void initCompass() {}
#endif
