#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)

#include "JoystickDriver.c"

void setMovementDrive(int power);
void setMovementTurn(int power);
task nxtDebugger();

task main()
{
	waitForStart();
	StartTask(nxtDebugger);

}

void setMovementDrive(int power) {
	power = (int)((float)power*(100.0*128.0));
	motor[leftmotor_1] = power;
	motor[leftmotor_2] = power;
	motor[rightmotor_1] = -power;
	motor[rightmotor_2] = -power;
}

void setMovementTurn(int power) {
	power = (int)((float)power*(100.0*128.0));
	motor[leftmotor_1] = power;
	motor[leftmotor_2] = power;
	motor[rightmotor_1] = power;
	motor[rightmotor_2] = power;
}

task nxtDebugger()
{
	while (true)
	{
		nxtDisplayCenteredTextLine(0, "Left Motor 1: %d", motor[leftmotor_1]);
		nxtDisplayCenteredTextLine(1, "Left Motor 2: %d", motor[leftmotor_2]);
		nxtDisplayCenteredTextLine(2, "Right Motor 1: %d", motor[rightmotor_1]);
		nxtDisplayCenteredTextLine(3, "Right Motor 2: %d", motor[rightmotor_2]);
		nxtDisplayCenteredTextLine(4, "Left Encoder: %d", nMotorEncoder[leftmotor_1]);
		nxtDisplayCenteredTextLine(5, "Right Encoder: %d", nMotorEncoder[rightmotor_1]);
	}
}
