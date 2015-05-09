/* backboard.c | Functions pertaining to the robot's backboard
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

//deprecated: use engageBackboard()
void engageBackboard_time() {
	motor[backboard] = BACKBOARD_MOTOR_SPEED;
	wait1Msec(BACKBOARD_MOTOR_UP_TIME);
	motor[backboard] = 0;
	isBackboardEngaged = true;
}

//deprecated: use disengageBackboard()
void disengageBackboard_time() {
	motor[backboard] = -BACKBOARD_MOTOR_SPEED;
	wait1Msec(BACKBOARD_MOTOR_DOWN_TIME);
	motor[backboard] = 0;
	isBackboardEngaged = false;
}

//deprecated: use toggleBackboard()
void toggleBackboard_time() {
	if (isBackboardEngaged)
		disengageBackboard_time();
	else
		engageBackboard_time();
}
