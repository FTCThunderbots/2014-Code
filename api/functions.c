// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"

// Goal-grabbing System

static bool isGoalGrabbed = false;
//static bool isHookInUse = false; // used to prevent the hook being opened and closed simultaneously

void initGrabSystem() {
	servo[grab] = GRAB_SERVO_BASE;
}

/* For a system in which the grab is a controlled motor
void grabGoal() {
	if (!isHookInUse) {
		isHookInUse = true;
		motor[grab] = GRAB_MOTOR_SPEED;
		while (nMotorEncoder[grab] != GRAB_MOTOR_CLOSED_POS) {}
		motor[grab] = 0;
		isGoalGrabbed = true;
		isHookInUse = false;
	}
} */

// If the grab is a servo, use this:
void grabGoal() {
	servo[grab] = GRAB_SERVO_BASE + GRAB_SERVO_CHANGE;
	isGoalGrabbed = true;
}

// Deprecated: only use if grab is a motor
task grabGoalTask() {
	grabGoal();
}

/*
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
*/

// Deprecated: only use if grab is a motor
void releaseGoal() {
	servo[grab] = GRAB_SERVO_BASE;
	isGoalGrabbed = false;
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

// Control from joysticks

void setBackboardServoJoystick() {
	if (joy1Btn(1))
		disengageBackboard(); // set to base
	if (joy1Btn(3))
		engageBackboard(); // set to target
}

void setGoalHookJoystick() {
	if (joy1Btn(2))
		grabGoal();
	if (joy1Btn(4))
		releaseGoal();
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
