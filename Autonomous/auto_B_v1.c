#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,            tServoStandard)

#define setting_twoEncoders
#include "../api/api.c"

task main() {
	initializeAPI();
	waitForStart();
   driveSecondsFW(3);
}