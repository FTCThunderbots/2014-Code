// backboard.c
// All of the functions that pertain to movement of the backboard

#include "backboard.h"

static bool isBackboardEngaged = false;

void engageBackboard() {
	motor[backboard] = BACKBOARD_MOTOR_SPEED;
	nMotorEncoderTarget[backboard] = BACKBOARD_MOTOR_DOWN_POS;
	while (nMotorRunState[backboard] != runStateIdle) {}
	motor[backboard] = 0;
	isBackboardEngaged = true;
}

void disengageBackboard() {
	motor[backboard] = -BACKBOARD_MOTOR_SPEED;
	nMotorEncoderTarget[backboard] = BACKBOARD_MOTOR_DOWN_POS;
	while (nMotorRunState[backboard] != runStateIdle) {}
	motor[backboard] = 0;
	isBackboardEngaged = false;
}

void toggleBackboard() {
	if (isBackboardEngaged)
		disengageBackboard();
	else
		engageBackboard();
}

void engageBackboard_time() {
	motor[backboard] = BACKBOARD_MOTOR_SPEED;
	wait1Msec(BACKBOARD_MOTOR_UP_TIME);
	motor[backboard] = 0;
	isBackboardEngaged = true;
}

void disengageBackboard_time() {
	motor[backboard] = -BACKBOARD_MOTOR_SPEED;
	wait1Msec(BACKBOARD_MOTOR_DOWN_TIME);
	motor[backboard] = 0;
	isBackboardEngaged = false;
}

void toggleBackboard_time() {
	if (isBackboardEngaged)
		disengageBackboard_time();
	else
		engageBackboard_time();
}
