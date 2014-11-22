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

	nNxtExitClicks = 3;
  static int delay = 0;
  static int i;
	while (nNxtButtonPressed != 3 && !matchHasStarted){
  	if (nNxtButtonPressed == 1)
  		delay += 1;
  	if (nNxtButtonPressed == 2)
  		delay -= 1;
  	/*
  	if (delay > 15)
  		delay = 0;
  	if (delay < 0)
  		delay = 15;
  		*/
  	if (nNxtButtonPressed == 0)
  	{
  		if (delay != 0)
  			i = 0;
  		else
  			i = 15;
  		delay = i;
  	}

  	nxtDisplayCenteredTextLine(0, "%2.2f second delay", delay);
  	wait1Msec(300);
  }
  eraseDisplay();

	waitForStart();
  driveSecondsBW(2.0);
  grab();
  rotateSecondsCW(0.5);
  waitSeconds(delay);
  driveSecondsFW(2.0);
}
