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

string label1 = "Timer:";
#define debugStreamLine1 label1
#define debugStreamType1 "%s"

float timerRuntime = 0;
#define debugStreamLine2 timerRuntime
#define debugStreamType2 "%.2f"

#include "../api/api.c"

task main()
{
	initializeAPI();
	Timer_t timer;
	pTimer_t ptimer = &timer;
	initTimer(ptimer);
	startTimer(ptimer);
	resetTimer(ptimer);

	setMovement(100,0);
	string loop1 = "Loop 1 (2)";
	printConsole(loop1);
	while (getRuntime(ptimer) < 2.0) {
		timerRuntime = getRuntime(ptimer);
	}

	setMovement(0,0);
	string loop2 = "Loop 2 (30)";
	printConsole(loop2);
	while (getDeciseconds(ptimer) < 30) {
		//nxtDisplayCenteredTextLine(3, "LOOP 2 %d ", getDeciseconds(ptimer));
		timerRuntime = getRuntime(ptimer);
	}

	resetTimer(ptimer);
	setMovement(-100, 0);

	string loop3 = "Loop 3 (2)";
	printConsole(loop3);
	while (getCentiseconds(ptimer) < 200) {
		timerRuntime = getRuntime(ptimer);
		//nxtDisplayCenteredTextLine(3, "LOOP 3 %d", getDeciseconds(ptimer));
	}

	setMovement(0,0);
	string loop4 = "Loop 4 (3)";
	printConsole(loop4);
  while (getMilliseconds(ptimer) < 3000) {
  	timerRuntime = getRuntime(ptimer);
  	//nxtDisplayCenteredTextLine(3, "LOOP 4 %d", getDeciseconds(pTimer));
  }

	resetTimer(ptimer);
	setMovement(0, 100);

	string loop5 = "Loop 5 (2)";
	printConsole(loop5);
	while (getRuntime(ptimer) < 2.0) {
		timerRuntime = getRuntime(ptimer);
		//nxtDisplayCenteredTextLine(3, "LOOP 5 %d", getDeciseconds(pTimer));
	}

	setMovement(0,0);
	string loop6 = "Loop 6 (3)";
	printConsole(loop6);
	while (getSeconds(ptimer) < 3) {
		timerRuntime = getRuntime(ptimer);
		//nxtDisplayCenteredTextLine(3, "LOOP 6 %d", getDeciseconds(pTimer));
	}

	resetTimer(ptimer);
	setMovement(0,-100);
	string loop7 = "Loop 7 (2)";

	while (getSeconds(ptimer) < 2) {
		timerRuntime = getRuntime(ptimer);
		//nxtDisplayCenteredTextLine(3, "LOOP 7 %d", getDeciseconds(pTimer));
	}

	setMovement(0,0);
	string loop8 = "Loop 8 (3)";
	printConsole(loop8);

	while (getDeciseconds(ptimer) < 30) {
		timerRuntime = getRuntime(ptimer);
		//nxtDisplayCenteredTextLine(3, "LOOP 8 %d", getDeciseconds(pTimer));
	}

	setMovement(100,100);

	resetTimer(ptimer);
	string loop9 = "Loop 9 (2)";
	printConsole(loop9);

	while (getSeconds(ptimer) < 2) {
		timerRuntime = getRuntime(ptimer);
		//nxtDisplayCenteredTextLine(3, "LOOP 9 %d", getDeciseconds(pTimer));
	}

	setMovement(0,0);
	string loop10 = "Loop 10 (3)";
	printConsole(loop10);

  while (getDeciseconds(ptimer) < 30) {
  	timerRuntime = getRuntime(ptimer);
  	//nxtDisplayCenteredTextLine(3, "LOOP 10 %d", getDeciseconds(pTimer));
  }

	setMovement(-100,-100);
	resetTimer(ptimer);
	string loop11 = "Loop 11 (2)";
	printConsole(loop11);

	while (getSeconds(ptimer) < 2) {
		timerRuntime = getRuntime(ptimer);
		//nxtDisplayCenteredTextLine(3, "LOOP 11 %d", getDeciseconds(pTimer));
	}

	setMovement(0,0);
	string loop12 = "Loop 12 (3)";
	printConsole(loop12);
  while (true) {
  	timerRuntime = getRuntime(ptimer);
  }
}

/*task updateTimeLocal() {
	while (true)
		time = (float)getMilliseconds(pTimer) / 1000;
}*/
