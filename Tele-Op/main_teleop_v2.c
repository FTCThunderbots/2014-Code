#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     grab,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backboard,     tmotorTetrix, openLoop)

#define setting_twoEncoders

#include "../api/api.c"

void displayDebugInfo();

static const bool DISPLAY_DEBUG_INFORMATION = false;

task main()
{
	initializeAPI();
	initializeRobot();
	while (true) {
		getJoystickSettings(joystick);
		//setMovementFromJoystickComposite(joystick.joy1_y1, joystick.joy1_x2);
		setMovement(correctJoystickComposite(joystick.joy1_y1), correctJoystickComposite(joystick.joy1_x2));
		setGoalHookJoystick();
		setBackboardServoJoystick();
		setSweeperJoystick();
		setConveyorJoystick();
		displayDebugInfo();
	}
}

void displayDebugInfo() {
	if (DISPLAY_DEBUG_INFORMATION) {
		//nxtDisplayCenteredTextLine(5, "GRAB: %d", nMotorEncoder[grab]);
		//nxtDisplayCenteredTextLine(6, "BACKBOARD: %d", servo[backboard]);
		//nxtDisplayCenteredTextLine(0, "sweep: %d", motor[sweep]);
		nxtDisplayCenteredTextLine(1, "left1: %d", motor[leftmotor_1]);
		nxtDisplayCenteredTextLine(2, "left2: %d", motor[leftmotor_2]);
		nxtDisplayCenteredTextLine(3, "right1: %d", motor[rightmotor_1]);
		nxtDisplayCenteredTextLine(4, "right2: %d", motor[rightmotor_2]);
	}
}
