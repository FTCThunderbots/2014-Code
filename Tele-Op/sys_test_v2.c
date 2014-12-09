#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          grab,          tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     lift,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     deflectorShield, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     motorL,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorM,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define setting_twoEncoders

#include "../api/api.c"

typedef enum Mode {
	SETPOWER,
	LEFT,
	RIGHT,
	DRIVE,
	ROTATE,
	SWEEPER,
	CONVEYOR,
	BACKBOARD,
	GOALHOOK,
	PROMPTEXIT
} Mode;

const string modeStrings[10] = {"Change power", "Left drive",
	"Right drive", "Parallel Drive", "Rotational Drive",
	"Sweep Motor", "Conveyor motor", "Backboard shield",
	"Goal-grabbing hook", "Exit program?"};

Mode nextMode(Mode m);
Mode lastMode(Mode m);
task cycleModes();

Mode currentMode = LEFT;
short power = 80;
const short powerIncrement = 5;

task main()
{
	nNxtExitClicks = 1000000;
	StartTask(cycleModes);

	while (power >= 0) {
		while (currentMode == SETPOWER) {
			while (nNxtButtonPressed == 2) {
				power -= powerIncrement;
				while (nNxtButtonPressed == 2) {
					EndTimeSlice();
				}
			}
			while (nNxtButtonPressed == 1) {
				power += powerIncrement;
				while (nNxtButtonPressed == 1)
					EndTimeSlice();
			}
			if (power < 0)
				break;
			else
				EndTimeSlice();
		}

		while (currentMode == LEFT) {
			while (nNxtButtonPressed == 2) {
				setMovement(-power, power);
				EndTimeSlice();
			}
			while (nNxtButtonPressed == 1) {
				setMovement(power, power);
				EndTimeSlice();
			}
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == RIGHT) {
			while (nNxtButtonPressed == 2) {
				setMovement(-power, -power);
				EndTimeSlice();
			}
			while (nNxtButtonPressed == 1) {
				setMovement(power, -power);
				EndTimeSlice();
			}
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == DRIVE) {
			while (nNxtButtonPressed == 2)
				setMovement(-power, 0);
				EndTimeSlice();
			while (nNxtButtonPressed == 1)
				setMovement(power, 0);
				EndTimeSlice();
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == ROTATE) {
			while (nNxtButtonPressed == 2) {
				setMovement(0, -power);
				EndTimeSlice();
			}
			while (nNxtButtonPressed == 1) {
				setMovement(0, power);
				EndTimeSlice();
			}
			setMovement(0, 0);
			EndTimeSlice();
		}

		while (currentMode == SWEEPER) {
			while (nNxtButtonPressed == 2) {
				motor[sweep] = -power;
				EndTimeSlice();
			}
			while (nNxtButtonPressed == 1) {
				motor[sweep] = power;
				EndTimeSlice();
			}
			motor[sweep] = 0;
			EndTimeSlice();
		}

		while (currentMode == CONVEYOR) {
			while (nNxtButtonPressed == 2) {
				motor[conveyor] = -power;
				EndTimeSlice();
			}
			while (nNxtButtonPressed == 1) {
				motor[conveyor] = power;
				EndTimeSlice();
			}
			motor[conveyor] = 0;
			EndTimeSlice();
		}

		while (currentMode == BACKBOARD) {
			while (nNxtButtonPressed == 2) {
				disengageBackboard();
				EndTimeSlice();
			}
			while (nNxtButtonPressed == 1) {
				engageBackboard();
				EndTimeSlice();
			}
			EndTimeSlice();
		}

		while (currentMode == GOALHOOK) {
			while (nNxtButtonPressed == 2) {
				releaseGoal();
				EndTimeSlice();
			}
			while (nNxtButtonPressed == 1) {
				grabGoal();
				EndTimeSlice();
			}
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
			nxtDisplayCenteredTextLine(0, modeStrings[currentMode]);
			while (nNxtButtonPressed == 3) {}
		}
		if (nNxtButtonPressed == 0) {
			currentMode = lastMode(currentMode);
			nxtDisplayCenteredTextLine(0, modeStrings[currentMode]);
			while (nNxtButtonPressed == 0) {}
		}
		EndTimeSlice();
	}
}

Mode nextMode(Mode m) {
	if (m == SETPOWER)
		return LEFT;
	else if (m == LEFT)
		return RIGHT;
	else if (m == RIGHT)
		return DRIVE;
	else if (m == DRIVE)
		return ROTATE;
	else if (m == ROTATE)
		return SWEEPER;
	else if (m == SWEEPER)
		return CONVEYOR;
	else if (m == CONVEYOR)
		return BACKBOARD;
	else if (m == BACKBOARD)
		return GOALHOOK;
	else if (m == GOALHOOK)
		return PROMPTEXIT;
	else //m == PROMPTEXIT
		return SETPOWER;
}

Mode lastMode(Mode m) {
	if (m == SETPOWER)
		return PROMPTEXIT;
	else if (m == PROMPTEXIT)
		return GOALHOOK;
	else if (m == GOALHOOK)
		return BACKBOARD;
	else if (m == BACKBOARD)
		return CONVEYOR;
	else if (m == CONVEYOR)
		return SWEEPER;
	else if (m == SWEEPER)
		return ROTATE;
	else if (m == ROTATE)
		return DRIVE;
	else if (m == DRIVE)
		return RIGHT;
	else if (m == RIGHT)
		return LEFT;
	else //m == LEFT
		return SETPOWER;
	
}
