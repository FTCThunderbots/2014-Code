// backboard.c
// All of the functions that pertain to movement of the backboard

#include "backboard.h"

static bool isBackboardEngaged = false;

void engageBackboard() {
	motor[backboard] = BACKBOARD_MOTOR_SPEED;
	wait1Msec(BACKBOARD_MOTOR_UP_TIME);
	motor[backboard] = 0;
	isBackboardEngaged = true;
}

void disengageBackboard() {
	motor[backboard] = -BACKBOARD_MOTOR_SPEED;
	wait1Msec(BACKBOARD_MOTOR_DOWN_TIME);
	motor[backboard] = 0;
	isBackboardEngaged = false;
}

void toggleBackboard() {
	if (isBackboardEngaged)
		disengageBackboard();
	else
		engageBackboard();
}
