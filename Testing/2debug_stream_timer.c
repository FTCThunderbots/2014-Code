#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     infrared,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightmotor_1,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     Lift1,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     Lift2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     Left2,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     Right2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     Sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     Flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    bucket,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    pin,                  tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code painstakingly hand written by Daniel Grimshaw, not by ROBOTC               !!*//

//settings are for last year's robot

// timer debug stream test

#define DEBUG_STREAM_ON

string label1 = "Runtime";
#define debugStreamLine1 label1
#define debugStreamType1 "%s"

float runtimeFloat = 0;
#define debugStreamLine2 runtimeFloat
#define debugStreamType2 "%.2f"

string label2 = "Timer Object";
#define debugStreamLine3 label2
#define debugStreamType3 "%s"

int timerTime = 0;
#define debugStreamLine5 timerTime
#define debugStreamType5 "%d"

int timerMins = 0;
#define debugStreamLine6 timerMins

long timerMS = 0;
#define debugStreamLine7 (int)timerMS
//string timerRunning = "run";
//#define debugStreamLine7 timerRunning
//#define debugStreamType7 "%s"

#define debugStreamLine8 (float)time10[T2]/100
#define debugStreamType8 "%.2f"

#define setting_twoMotors

#include "../api/api.c"

task main() {
	ClearTimer(T2);
	initializeAPI();
	Timer_t t;
	pTimer_t p = &t;
	initTimer(p);
	resetTimer(p);
	startTimer(p);
	while(true) {
		updateTimer(p);
		runtimeFloat = runtime();
		timerTime = getSeconds(p);
		timerMins = t.time.mins;
		timerMS = t.time.msecs;
		/*
		if (t.running)
			timerRunning = "run";
		else
			timerRunning = "pause";
		*/
		if (nNxtButtonPressed == 3) {
			toggleTimer(p);
			ClearTimer(T2);
			wait1Msec(500);
		}
		if (nNxtButtonPressed == 1) {
			resetTimer(p);
			ClearTimer(T2);
			wait1Msec(500);
		}
	}
}
