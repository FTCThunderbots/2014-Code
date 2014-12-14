// grab.c
// All of the functions pertaining to the grab mechanism

#include "grab.h"

static bool isGoalGrabbed = false;

void grabGoal() {
	motor[grab] = GRAB_MOTOR_SPEED;
	wait1Msec(GRAB_MOTOR_TIME);
	motor[grab] = 0;
	isGoalGrabbed = true;
}

void releaseGoal() {
	motor[grab] = -GRAB_MOTOR_SPEED;
	wait1Msec(GRAB_MOTOR_TIME);
	motor[grab] = 0;
	isGoalGrabbed = false;
}

void toggleGrab() {
	if (isGoalGrabbed)
		releaseGoal();
	else
		grabGoal();
}
