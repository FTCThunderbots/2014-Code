#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     grab,					 tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     rightmotor_2,  tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backboard,     tmotorTetrix, openLoop)

#define setting_twoEncoders




#include "../api/api.c"

task main() {
	//encoder based off ramp, grab 60cm, drag to park zone
	initializeAPI();
	initializeRobot();
	startTask(matchStartListener);
	int delay = setAutoDelay(); // implemented: api/nxt.c
	while(!matchHasStarted) {/* wait for start*/}
	waitSeconds(delay);
	driveInches(84, -100);
	grabGoal();
	swingDegrees(90, 1, 10);
	driveInches(24, 100);
	swingDegrees(90, -1, 10);
	driveInches(74, 100);
	swingDegrees(90, 1, 10);
	driveInches(36, 50);
	releaseGoal();
}
