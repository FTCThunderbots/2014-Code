#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
//*!!Code painstakingly handwritten by Pranav M, not by ROBOTC             !!*//

#define setting_twoEncoders

#include "../api/api.c"

bool userIsAGoat() {
	return false;
}

void setOldMovementPower(int power, int turn);

bool userIsNotAGoat() {
	return !userIsAGoat();
}

void scaleInputs(int *x, int *y);

task main()
{
	initializeAPI();
	while (userIsNotAGoat()) {
		int a = 0;
		int b = 0;
		getJoystickSettings(joystick);
		setMovementFromJoystick(joystick.joy1_y1, joystick.joy1_x2);
		if (joy1Btn(2)) {
			motor[sweep] = 100;
			motor[conveyor] = 100;
		}
		else {
			if (!(joy2Btn(6) || joy2Btn(8) || joy2Btn(5) || joy2Btn(7)))
				motor[sweep] = 0;
			else if (joy2Btn(6))
				motor[sweep] = 100;
			else if (joy2Btn(8))
				motor[sweep] = 50;
			else if (joy2Btn(5))
				motor[sweep] = -100;
			else
				motor[sweep] = -50;


		a = joystick.joy2_y1;
		if (abs(a)<10) a = 0;
		b = 100;
		scaleInputs(&a, &b);
		motor[conveyor] = a/2;
	}
		nxtDisplayCenteredTextLine(5, "conveyor: %d", motor[conveyor]);
		nxtDisplayCenteredTextLine(0, "sweep: %d", motor[sweep]);
		nxtDisplayCenteredTextLine(1, "left1: %d", motor[leftmotor_1]);
		nxtDisplayCenteredTextLine(2, "left2: %d", motor[leftmotor_2]);
		nxtDisplayCenteredTextLine(3, "r1: %d", motor[rightmotor_1]);
		nxtDisplayCenteredTextLine(4, "r2: %d", motor[rightmotor_2]);
	}
}

void scaleInputs(int* x, int* y) {
	float fx = (float)*x;
	float fy = (float)*y;
	if (abs(*x) > 100)
	{
		fy *= (100.0 / (float)abs(*x));
		fx *= (100.0 / (float)abs(*x));
	}
	if (abs(*y) > 100)
	{
		fx *= (100.0 / (float)abs(*y));
		fy *= (100.0 / (float)abs(*y));
	}
	*x = (int)fx;
	*y = (int)fy;
}
