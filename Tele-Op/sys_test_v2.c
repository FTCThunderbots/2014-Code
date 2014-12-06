#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          grab,          tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)

#define setting_twoEncoders

#include "../api/api.c"

#define PRESSTIME 300 // in milliseconds

typedef enum Mode {
	LEFT,
	RIGHT,
	DRIVE,
	ROTATE,
	SWEEPER,
	CONVEYOR,
	BACKBOARD,
	GOALHOOK
} Mode;

const string modeStrings[6] = {"Left drive", "Right drive",
	"Parallel Drive", "Rotational Drive", "Sweep Motor",
	"Conveyor motor"};

Mode nextMode(Mode m);
Mode lastMode(Mode m);
task cycleModes();

Mode currentMode = LEFT;

task main()
{
	nNxtExitClicks = 100;
	StartTask(cycleModes);

	while (true) {
		while (currentMode == LEFT) {
			while (nNxtButtonPressed == 2)
				setMovement(-100, 100);
			while (nNxtButtonPressed == 1)
				setMovement(100, 100);
			setMovement(0, 0);
		}

		while (currentMode == RIGHT) {
			while (nNxtButtonPressed == 2)
				setMovement(-100, -100);
			while (nNxtButtonPressed == 1)
				setMovement(100, -100);
			setMovement(0, 0);
		}

		while (currentMode == DRIVE) {
			while (nNxtButtonPressed == 2)
				setMovement(-100, 0);
			while (nNxtButtonPressed == 1)
				setMovement(100, 0);
			setMovement(0, 0);
		}

		while (currentMode == ROTATE) {
			while (nNxtButtonPressed == 2)
				setMovement(0, -100);
			while (nNxtButtonPressed == 1)
				setMovement(0, 100);
			setMovement(0, 0);
		}

		while (currentMode == SWEEPER) {
			while (nNxtButtonPressed == 2)
				motor[sweep] = -100;
			while (nNxtButtonPressed == 1)
				motor[sweep] = 100;
			motor[sweep] = 0;
		}

		while (currentMode == CONVEYOR) {
			while (nNxtButtonPressed == 2)
				motor[conveyor] = -100;
			while (nNxtButtonPressed == 1)
				motor[conveyor] = 100;
			motor[conveyor] = 0;
		}
	}
}

task cycleModes() {
	while (true) {
		nxtDisplayCenteredTextLine(0, modeStrings[currentMode]);
		if (nNxtButtonPressed == 3) {
			currentMode = nextMode(currentMode);
			wait1Msec(PRESSTIME);
		}
		if (nNxtButtonPressed == 0) {
			currentMode = lastMode(currentMode);
			wait1Msec(PRESSTIME);
		}
	}
}

Mode nextMode(Mode m) {
	if (m == LEFT)
		return RIGHT;
	if (m == RIGHT)
		return DRIVE;
	if (m == DRIVE)
		return ROTATE;
	if (m == ROTATE)
		return SWEEPER;
	if (m == SWEEPER)
		return CONVEYOR;
	if (m == CONVEYOR)
		return BACKBOARD;
	if (m == BACKBOARD)
		return GOALHOOK;
	return LEFT;
}

Mode lastMode(Mode m) {
	if (m == RIGHT)
		return LEFT;
	if (m == DRIVE)
		return RIGHT;
	if (m == ROTATE)
		return DRIVE;
	if (m == SWEEPER)
		return ROTATE;
	if (m == CONVEYOR)
		return SWEEPER;
	if (m == BACKBOARD)
		return CONVEYOR;
	if (m == GOALHOOK)
		return BACKBOARD;
	return GOALHOOK;
}
