/* grab.c | Functions pertaining to the goal-grabbing hook
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

#include "grab.h"

static bool isGoalGrabbed = false;

void grabGoal() {
	motor[grab] = GRAB_MOTOR_SPEED;
	nMotorEncoderTarget[grab] = -GRAB_MOTOR_DOWN_POS;
	while (nMotorRunState[grab] != runStateIdle) {}
	motor[grab] = 0;
	isGoalGrabbed = true;
}

void releaseGoal() {
	motor[grab] = -GRAB_MOTOR_SPEED;
	nMotorEncoderTarget[grab] = GRAB_MOTOR_UP_POS;
	while (nMotorRunState[grab] != runStateIdle) {}
	motor[grab] = 0;
	isGoalGrabbed = false;
}

void toggleGrab() {
	if (isGoalGrabbed)
		releaseGoal();
	else
		grabGoal();
}

void grabGoal_time() {
	motor[grab] = GRAB_MOTOR_SPEED;
	wait1Msec(GRAB_MOTOR_DOWN_TIME);
	motor[grab] = 0;
	isGoalGrabbed = true;
}

//deprecated: use releaseGoal()
void releaseGoal_time() {
	motor[grab] = -GRAB_MOTOR_SPEED;
	wait1Msec(GRAB_MOTOR_UP_TIME);
	motor[grab] = 0;
	isGoalGrabbed = false;
}

//deprecated: use toggleGrab()
void toggleGrab_time() {
	if (isGoalGrabbed)
		releaseGoal_time();
	else
		grabGoal_time();
}
