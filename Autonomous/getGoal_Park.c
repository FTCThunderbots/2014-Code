#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,     tServoStandard)
#pragma config(Servo,	 srvo_S1_C4_2,    grab,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,				 tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,				 tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,				 tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,				 tServoNone)

#define setting_twoEncoders

#include "../api/api.c"

task main() {
	//time based off ramp, grab, drive straight to park zone
	initializeAPI();
	initializeRobot();
	int delay = setAutoDelay(); // implemented: api/nxt.c
	waitStartAPI();  // implemented: api/nxt.c
	waitSeconds(delay);
	driveSecondsBW(2.0);
	grabGoal();
	rotateSecondsCW(0.5);
	waitSeconds(delay);
	driveSecondsFW(2.0);
}
