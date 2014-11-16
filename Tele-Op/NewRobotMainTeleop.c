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

bool userIsNotAGoat() {
	return !userIsAGoat();
}

void backupSetMovementJoystick(byte foward, byte turn);

task main()
{
	initializeAPI();
	while (userIsNotAGoat()) {
		int a = 0;
		int b = 0;
		getJoystickSettings(joystick);
		backupSetMovementJoystick(-joystick.joy1_y1, -joystick.joy1_x2);
		if (!(joy1Btn(6) || joy1Btn(8) || joy1Btn(5) || joy1Btn(7)))
			motor[sweep] = 0;
		else if (joy1Btn(6))
			motor[sweep] = 100;
		else if (joy1Btn(8))
			motor[sweep] = 50;
		else if (joy1Btn(5))
			motor[sweep] = -100;
		else
			motor[sweep] = -50;

		a = joystick.joy2_y1;
		b = 100;
		scaleInputs(&a, &b);
		motor[conveyor] = a/2;
		nxtDisplayCenteredBigTextLine(5, "%d", motor[conveyor]);
	}
}

void backupSetMovementJoystick(byte foward, byte turn){
	if (abs(foward) <= 10) foward = 0;
	if (abs(turn) <= 10) turn = 0;
	foward = (byte)((float)foward * (100.0/128.0));
	turn = (byte)((float)turn * (100.0/128.0));
	setMovement(foward,turn);
}
