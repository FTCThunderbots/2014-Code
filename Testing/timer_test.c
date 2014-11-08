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

#define timersused 1
#define setting_twoMotors
#define DEBUG_STREAM_ON
/*float time = 0;
#define debugStreamLine1 time
#define debugStreamType1 "%.2f"*/

#include "../api/api.c"

//Timer_t timer;
//pTimer_t pTimer = &timer;

//task updateTimeLocal();

task main()
{
	initializeAPI();

	Timer_t timer;
	pTimer_t pTimer = &timer;
	initTimer(pTimer);
	startTimer(pTimer);
	pTimer->milliseconds = 0;

	//StartTask(updateTimeLocal);

	setMovement(100,0);
	while (getSeconds(pTimer) < 2) {nxtDisplayCenteredTextLine(3, "LOOP 1 %d", getDeciseconds(pTimer));}
	setMovement(0,0);

	while (getDeciseconds(pTimer) < 30) {nxtDisplayCenteredTextLine(3, "LOOP 2 %d ", getDeciseconds(pTimer));}

	resetTimer(pTimer);
	setMovement(-100, 0);
	while (getCentiseconds(pTimer) < 200) {nxtDisplayCenteredTextLine(3, "LOOP 3 %d", getDeciseconds(pTimer));}
        setMovement(0,0);
        while (getMilliseconds(pTimer) < 3000) {nxtDisplayCenteredTextLine(3, "LOOP 4 %d", getDeciseconds(pTimer));}

	resetTimer(pTimer);
	setMovement(0, 100);
	while (getRuntime(pTimer) < 2.0) {nxtDisplayCenteredTextLine(3, "LOOP 5 %d", getDeciseconds(pTimer));}
        setMovement(0,0);
        while (getSeconds(pTimer) < 3) {nxtDisplayCenteredTextLine(3, "LOOP 6 %d", getDeciseconds(pTimer));}

	resetTimer(pTimer);
	setMovement(0,-100);
	while (getSeconds(pTimer) < 2) {nxtDisplayCenteredTextLine(3, "LOOP 7 %d", getDeciseconds(pTimer));}
        setMovement(0,0);
        while (getDeciseconds(pTimer) < 30) {nxtDisplayCenteredTextLine(3, "LOOP 8 %d", getDeciseconds(pTimer));}

	resetTimer(pTimer);
	setMovement(100,100);
	while (getSeconds(pTimer) < 2) {nxtDisplayCenteredTextLine(3, "LOOP 9 %d", getDeciseconds(pTimer));}
        setMovement(0,0);
        while (getDeciseconds(pTimer) < 30) {nxtDisplayCenteredTextLine(3, "LOOP 10 %d", getDeciseconds(pTimer));}

	resetTimer(pTimer);
	setMovement(-100,-100);
	while (getSeconds(pTimer) < 2) {nxtDisplayCenteredTextLine(3, "LOOP 11 %d", getDeciseconds(pTimer));}
        setMovement(0,0);
  while (true) {nxtDisplayCenteredTextLine(3, "LOOP 12 %d", getDeciseconds(pTimer));}
}

/*task updateTimeLocal() {
	while (true)
		time = (float)getMilliseconds(pTimer) / 1000;
}*/
