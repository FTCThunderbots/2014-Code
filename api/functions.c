// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"

bool grabbed = false;

void grabGoal() {
	nMotorEncoderTarget[grab] = GRAB_SERVO_INIT + GRAB_SERVO_CHANGE;
	motor[grab] = 50;
	grabbed = true;
}

void releaseGoal() {
	nMotorEncoderTarget[GRAB_SERVO_INIT];
	motor[grab] = -50;
	grabbed = false;
}

void toggleGrab() {
	if (grabbed)
		releaseGoal();
	else
		grabGoal();
}
