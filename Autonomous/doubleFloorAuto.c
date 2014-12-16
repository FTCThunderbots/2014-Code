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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


#define setting_twoEncoders
#include "../api/api.c"

task main() {
	//time based off ramp
	initializeAPI();
	initializeRobot();
	waitForStart();
	//driveSeconds(2.0, 100);
	ClearTimer(T1);
	int a = time1[T1];
	while (time1[T1] < a + 1500) {
		setMovement(100, 0);
	}
	setMovement(0, 0);

	a = time1[T1];
	while (time1[T1] < a + 1500) {
		setMovement(-35, 0);
	}
	setMovement(0, 0);

	wait1Msec(5000);

	a = time1[T1];
	while (time1[T1] < a + 1000) {
		setMovement(100, 0);
	}
	setMovement(0, 0);
}
