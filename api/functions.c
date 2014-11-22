// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"

void grabGoal() {
	servo[grab] = GRAB_SERVO_INIT + GRAB_SERVO_CHANGE;
}