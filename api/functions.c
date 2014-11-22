// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"

bool grabbed = false;

void grabGoal() {
	motor[grab] = 50;
	while (nMotorEncoder[grab] != 110) {}
	motor[grab] = 0;
	grabbed = true;
}

void releaseGoal() {
	motor[grab] = -50;
	while (nMotorEncoder[grab] != 0) {}
	motor[grab] = 0;
	grabbed = false;
}

void toggleGrab() {
	if (grabbed)
		releaseGoal();
	else
		grabGoal();
}
