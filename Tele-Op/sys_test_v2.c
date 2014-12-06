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
	SETPOWER,
	LEFT,
	RIGHT,
	DRIVE,
	ROTATE,
	SWEEPER,
	CONVEYOR,
	BACKBOARD,
	GOALHOOK
} Mode;

const string modeStrings[7] = {"Change power", "Left drive",
	"Right drive", "Parallel Drive", "Rotational Drive",
	"Sweep Motor", "Conveyor motor"};

Mode nextMode(Mode m);
Mode lastMode(Mode m);
task cycleModes();

Mode currentMode = LEFT;
short power = 80;

task main()
{
	nNxtExitClicks = 100;
	StartTask(cycleModes);

	while (true) {
		while (currentMode == SETPOWER) {
			
		}
		
		while (currentMode == LEFT) {
			while (nNxtButtonPressed == 2)
				setMovement(-power, power);
			while (nNxtButtonPressed == 1)
				setMovement(power, power);
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == RIGHT) {
			while (nNxtButtonPressed == 2)
				setMovement(-power, -power);
			while (nNxtButtonPressed == 1)
				setMovement(power, -power);
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == DRIVE) {
			while (nNxtButtonPressed == 2)
				setMovement(-power, 0);
			while (nNxtButtonPressed == 1)
				setMovement(power, 0);
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == ROTATE) {
			while (nNxtButtonPressed == 2)
				setMovement(0, -power);
			while (nNxtButtonPressed == 1)
				setMovement(0, power);
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == SWEEPER) {
			while (nNxtButtonPressed == 2)
				motor[sweep] = -power;
			while (nNxtButtonPressed == 1)
				motor[sweep] = power;
			motor[sweep] = 0;
			EndTimeSlice();
		}

		while (currentMode == CONVEYOR) {
			while (nNxtButtonPressed == 2)
				motor[conveyor] = -power;
			while (nNxtButtonPressed == 1)
				motor[conveyor] = power;
			motor[conveyor] = 0;
			EndTimeSlice();
		}
		
		while (currentMode == BACKBOARD) {
			while (nNxtButtonPressed == 2)
				disengageBackboard();
			while (nNxtButtonPressed == 1)
				engageBackboard();
			EndTimeSlice();
		}
		
		while (currentMode == GOALHOOK) {
			while (nNxtButtonPressed == 2)
				releaseGoal();
			while (nNxtButtonPressed == 1)
				grabGoal();
			EndTimeSlice();
		}
	}
}

task cycleModes() {
	while (true) {
		nxtDisplayCenteredTextLine(0, modeStrings[currentMode]);
		nxtDisplayCenteredTextLine(1, "Power: %d", power);
		if (nNxtButtonPressed == 3) {
			currentMode = nextMode(currentMode);
			wait1Msec(PRESSTIME);
		}
		if (nNxtButtonPressed == 0) {
			currentMode = lastMode(currentMode);
			wait1Msec(PRESSTIME);
		}
		EndTimeSlice();
	}
}

Mode nextMode(Mode m) {
	if (m == SETPOWER)
		return LEFT;
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
	return SETPOWER;
}

Mode lastMode(Mode m) {
	if (m == LEFT)
		return SETPOWER;
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