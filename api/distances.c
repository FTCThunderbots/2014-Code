// distances.c
// Contains code for managing distances on the field

#include "distances.h"

void waitDriveTicks(long ticks) {
	Ruler_t ruler;
	initSysRuler(&ruler);
	ticks = abs(ticks);
	while (abs(getDriveTicks(&ruler)) < ticks) {};
	destroySysRuler();
}

void waitStrafeTicks(long ticks) {
	Ruler_t ruler;
	initSysRuler(&ruler);
	ticks = abs(ticks);
	while (abs(getStrafeTicks(&ruler)) < ticks) {};
	destroySysRuler();
}

void waitRotateTicks(long ticks) {
	Ruler_t ruler;
	initSysRuler(&ruler);
	ticks = abs(ticks);
	while (abs(getRotateTicks(&ruler)) < ticks) {};
	destroySysRuler();
}

void waitSwingTicks(long ticks) {
	Ruler_t ruler;
	initSysRuler(&ruler);
	ticks = abs(ticks);
	while (abs(getSwingTicks(&ruler)) < ticks) {};
	destroySysRuler();
}

void waitDriveInches(float inches) {
	waitDriveTicks(inchesToDriveTicks(inches));
}

void waitStrafeInches(float inches) {
	waitStrafeTicks(inchesToStrafeTicks(inches));
}

void waitRotateDegrees(float degrees) {
	waitRotateTicks(degreesToRotateTicks(degrees));
}

void waitSwingDegrees(float degrees) {
	waitSwingTicks(degreesToSwingTicks(degrees));
}
