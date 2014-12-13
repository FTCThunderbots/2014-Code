// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"

// Goal-grabbing System

static bool isGoalGrabbed = false;
static bool isBackboardEngaged = false;

// For a system in which the grab is a controlled motor
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


// Backboard servo

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

// Control from joysticks

#warn "This is a temporary fix in functions.c, please set times"

void setBackboardJoystick() {
	if (joy2Btn(1))
		motor[backboard] = BACKBOARD_MOTOR_SPEED;
	else if (joy2Btn(3))
		motor[backboard] = -BACKBOARD_MOTOR_SPEED;
	else
		motor[backboard] = 0;
}

void setGoalHookJoystick() {
	if (joy1Btn(2))
		motor[grab] = GRAB_MOTOR_SPEED;
	else if (joy1Btn(4))
		motor[grab] = -GRAB_MOTOR_SPEED;
	else
		motor[grab] = 0;
}

void setSweeperJoystick() {
	if (joy2Btn(1) || joy2Btn(4))
		motor[sweep] = SWEEP_MOTOR_SLOW_SPEED; // 40
	else if (joy2Btn(5) || joy2Btn(2))
		motor[sweep] = -SWEEP_MOTOR_SPEED; // 100
	else if (joy2Btn(7))
  		motor[sweep] = SWEEP_MOTOR_SPEED; // -100
	else
		motor[sweep]= 0;
}

void setConveyorJoystick() {
	if (joy2Btn(3) || joy2Btn(4))
		motor[conveyor] = CONVEYOR_MOTOR_SLOW_SPEED; // 40
	else if (joy2Btn(6) || joy2Btn(2))
		motor[conveyor] = CONVEYOR_MOTOR_SPEED; // 100
	else if (joy2Btn(8))
		motor[conveyor] = -CONVEYOR_MOTOR_SPEED; // -100
	else
		motor[conveyor] = 0;
}
