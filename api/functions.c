// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"

// Goal-grabbing System

static bool isGoalGrabbed = false;
static bool isHookInUse = false; // used to prevent the hook being opened and closed simultaneously

void initGrabSystem() {
	nMotorEncoder[grab] = 0;
}

void grabGoal() {
	if (!isHookInUse) {
		isHookInUse = true;
		motor[grab] = GRAB_MOTOR_SPEED;
		while (nMotorEncoder[grab] != GRAB_MOTOR_CLOSED_POS) {}
		motor[grab] = 0;
		isGoalGrabbed = true;
		isHookInUse = false;
	}
}

task grabGoalTask() {
	grabGoal();
}

void releaseGoal() {
	if (!isHookInUse) {
		isHookInUse = true;
		motor[grab] = -GRAB_MOTOR_SPEED;
		while (nMotorEncoder[grab] != GRAB_MOTOR_OPEN_POS) {}
		motor[grab] = 0;
		isGoalGrabbed = false;
		isHookInUse = false;
	}
}

task releaseGoalTask() {
	releaseGoal();
}

void toggleGrab() {
	if (isGoalGrabbed)
		releaseGoal();
	else
		grabGoal();
}

task toggleGrabTask() {
	toggleGrab();
}

// Backboard servo

void initBackboardServo() {
	disengageBackboard();
}

void engageBackboard() {
	servo[backboard] = BACKBOARD_SERVO_TARGET;
}

void disengageBackboard() {
	servo[backboard] = BACKBOARD_SERVO_BASE;
}