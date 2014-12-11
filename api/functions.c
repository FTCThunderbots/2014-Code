// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"

// Goal-grabbing System

static bool isGoalGrabbed = false;
static bool isBackboardEngaged = false;
static bool isHookInUse = false; // used to prevent the hook being opened and closed simultaneously
static bool isBackboardInUse = false;

void initGrabSystem() {
	//servo[grab] = GRAB_SERVO_BASE;
	// for now, just do nothing
}

// For a system in which the grab is a controlled motor
void grabGoal() {
	if (!isHookInUse) {
		isHookInUse = true;
		motor[grab] = GRAB_MOTOR_SPEED;
		wait1Msec(GRAB_MOTOR_TIME);
		motor[grab] = 0;
		isGoalGrabbed = true;
		isHookInUse = false;
	}
}

/* If the grab is a servo, use this:
void grabGoal() {
	servo[grab] = GRAB_SERVO_BASE + GRAB_SERVO_CHANGE;
	isGoalGrabbed = true;
} */

// Deprecated: only use if grab is a motor
task grabGoalTask() {
	grabGoal();
}

void releaseGoal() {
	if (!isHookInUse) {
		isHookInUse = true;
		motor[grab] = -GRAB_MOTOR_SPEED;
		wait1Msec(GRAB_MOTOR_TIME);
		motor[grab] = 0;
		isGoalGrabbed = false;
		isHookInUse = false;
	}
}

/* For use if grab is a servo
void releaseGoal() {
	servo[grab] = GRAB_SERVO_BASE;
	isGoalGrabbed = false;
} */

// Deprecated: only use if grab is a motor
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
	//disengageBackboard();
	// do nothing for now
}

void engageBackboard() {
	if (!isBackboardInUse) {
		isBackboardInUse = true;
		motor[backboard] = BACKBOARD_MOTOR_SPEED;
		wait1Msec(BACKBOARD_MOTOR_UP_TIME);
		motor[backboard] = 0;
		isBackboardEngaged = true;
		isBackboardInUse = false;
	}
}

task engageBackboardTask() {
	engageBackboard();
}

void disengageBackboard() {
	if (!isBackboardInUse) {
		isBackboardInUse = true;
		motor[backboard] = -BACKBOARD_MOTOR_SPEED;
		wait1Msec(BACKBOARD_MOTOR_DOWN_TIME);
		motor[backboard] = 0;
		isBackboardEngaged = false;
		isBackboardInUse = false;
	}
}

task disengageBackboardTask() {
	disengageBackboard();
}

void toggleBackboard() {
	if (isBackboardEngaged)
		disengageBackboard();
	else
		engageBackboard();
}

task toggleBackboardTask() {
	toggleBackboard();
}

// Control from joysticks

void setBackboardServoJoystick() {
	if (joy1Btn(1))
		//StartTask(disengageBackboardTask);
		disengageBackboard();
	if (joy1Btn(3))
		//StartTask(engageBackboardTask);
		engageBackboard();
}

void setGoalHookJoystick() {
	if (joy1Btn(2))
		StartTask(grabGoalTask);
	if (joy1Btn(4))
		StartTask(releaseGoalTask);
}

void setSweeperJoystick() {
	if (joy2Btn(1) || joy2Btn(4))
		motor[sweep] = SWEEP_MOTOR_SLOW_SPEED; // 40
	else if (joy2Btn(5) || joy2Btn(2))
		motor[sweep] = SWEEP_MOTOR_SPEED; // 100
	else if (joy2Btn(7))
  	motor[sweep] = -SWEEP_MOTOR_SPEED; // -100
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
