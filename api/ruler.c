// ruler.c
// A custom encoder measurement system
// Should be very useful

#include "ruler.h"

#ifndef rulersused
#define rulersused 1
#endif

static pRuler_t rulerSet[rulersused];
static pRuler_t sysRuler;

static bool sysRulerExists;
static byte rulers = 0;

int initRuler(pRuler_t ruler) {
	if (ruler->initialized)
		return -1;
	resetRuler(ruler);
	ruler->running = true;
	ruler->initialized = true;
	rulerSet[rulers++] = ruler;

	return 0;
}

int initSysRuler(pRuler_t ruler) {
	if (ruler->initialized)
		return -1;
	resetRuler(ruler);
	ruler->running = true;
	ruler->initialized = true;
	sysRuler = ruler;
	sysRulerExists = true;
	return 0;
}

void destroySysRuler() {
	sysRulerExists = false;
	// Anything else should be done in context
}

void startRuler(pRuler_t ruler) {
	ruler->previous.left1 = ruler->ticks.left1;
	ruler->previous.left2 = ruler->ticks.left2;
	ruler->previous.right1 = ruler->ticks.right1;
	ruler->previous.right2 = ruler->ticks.right2;



	ruler->ticks.left1 = nMotorEncoder[leftmotor_1];
	ruler->ticks.left2 = nMotorEncoder[leftmotor_2];
	ruler->ticks.right1 = nMotorEncoder[rightmotor_1];
	ruler->ticks.right2 = nMotorEncoder[rightmotor_2];

	ruler->running = true;
}

void stopRuler(pRuler_t ruler) {
	ruler->running = false;
}

void resetRuler(pRuler_t ruler) {
	ruler->start.left1 = nMotorEncoder[leftmotor_1];
	ruler->start.left2 = nMotorEncoder[leftmotor_2];
	ruler->start.right1 = nMotorEncoder[rightmotor_1];
	ruler->start.right2 = nMotorEncoder[rightmotor_2];

	ruler->previous.left1 = 0;
	ruler->previous.left2 = 0;
	ruler->previous.right1 = 0;
	ruler->previous.right2 = 0;

	ruler->ticks.left1 = 0;
	ruler->ticks.left2 = 0;
	ruler->ticks.right1 = 0;
	ruler->ticks.right2 = 0;
}

void updateRuler(pRuler_t ruler) {
	if (ruler->running) {
		ruler->ticks.left1 = nMotorEncoder[leftmotor_1] - ruler->start.left1 + ruler->previous.left1;
		ruler->ticks.left2 = nMotorEncoder[leftmotor_2] - ruler->start.left2 + ruler->previous.left2;
		ruler->ticks.right1 = nMotorEncoder[rightmotor_1] - ruler->start.right1 + ruler->previous.right1;
		ruler->ticks.right2 = nMotorEncoder[rightmotor_2] - ruler->start.right2 + ruler->previous.right2;
	}
}

void updateAllRulers() {
	for (int i = 0; i < rulers; i++)
		updateRuler(rulerSet[i]);
	if (sysRulerExists)
		updateRuler(sysRuler);
}

long getLeftTicks(pRuler_t ruler) {
	return AVG(ruler->ticks.left1, ruler->ticks.left2);
}

long getRightTicks(pRuler_t ruler) {
	return AVG(ruler->ticks.right1, ruler->ticks.right2);
}

long getFrontTicks(pRuler_t ruler) {
	return AVG(ruler->ticks.left1, ruler->ticks.right1);
}

long getBackTicks(pRuler_t ruler) {
	return AVG(ruler->ticks.left2, ruler->ticks.right2);
}

long getDriveTicks(pRuler_t ruler) {
	return AVG(-getLeftTicks(ruler), getRightTicks(ruler));
}

long getStrafeTicks(pRuler_t ruler) {
	return AVG(-getFrontTicks(ruler), getBackTicks(ruler));
}

long getRotateTicks(pRuler_t ruler) {
	return -AVG(getLeftTicks(ruler), getRightTicks(ruler));
}

long getSwingTicks(pRuler_t ruler) {
	return -(getLeftTicks(ruler) + getRightTicks(ruler));
	// Not dividing by two is intentional here, since one side should be zero.
}

float getDriveInches(pRuler_t ruler) {
   return driveTicksToInches(getDriveTicks(ruler));
}

float getDriveCentimeters(pRuler_t ruler) {
   return inToCm(getDriveInches(ruler));
}

float getStrafeInches(pRuler_t ruler) {
   return strafeTicksToInches(getStrafeTicks(ruler));
}

float getRotateDegrees(pRuler_t ruler) {
	return rotateTicksToDegrees(getRotateTicks(ruler));
}

float getSwingDegrees(pRuler_t ruler) {
   return swingTicksToDegrees(getSwingTicks(ruler));
}


float getDriveCentimeters(pRuler_t ruler) {
   return driveTicksToCentimeters(getDriveTicks(ruler));
}

float getStrafeCentimeters(pRuler_t ruler) {
   return strafeTicksToCentimeters(getStrafeTicks(ruler));
}

// Current encoder positions: cannot be done because the raw encoder values will be messed up
