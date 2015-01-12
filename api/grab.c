// grab.c
// All of the functions pertaining to the grab mechanism

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
