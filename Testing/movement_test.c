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

#define setting_twoEncoders

long leftEnc = 0;
long rightEnc = 0;
long driveIn = 0;
long rotateIn = 0;
long swingIn = 0;
string state = "";

#define DEBUG_STREAM_ON
#define debugStreamLine1 "Raw Values"
#define debugStreamLine2 (int)leftEnc
#define debugStreamLine3 (int)rightEnc
#define debugStreamLine4 "Ruler object"
#define debugStreamLine5 (int)driveIn
#define debugStreamLine6 (int)rotateIn
#define debugStreamLine7 (int)swingIn
#define debugStreamLine8 state

/*
#define debugStreamType5 "%.2f"
#define debugStreamType6 "%.2f"
#define debugStreamType7 "%.2f"
#define debugStreamType8 "%s"
*/
#define setting_twoMotors
#include "../api/api.c"

Ruler_t ruler;
pRuler_t pruler = &ruler;

void stopForASecond(void);
task measureEncoders();

task main()
{
	StartTask(measureEncoders);
	initializeAPI();
  initRuler(pruler);
	setMovement(100,0);
	wait1Msec(2000);
	stopForASecond();
	setMovement(-100, 0);
	wait1Msec(2000);
	stopForASecond();
	setMovement(0, 100);
	wait1Msec(2000);
	stopForASecond();
	setMovement(0,-100);
	wait1Msec(2000);
	stopForASecond();
	setMovement(100,100);
	wait1Msec(2000);
	stopForASecond();
	setMovement(-100,-100);
	wait1Msec(2000);
	stopForASecond();
}

void stopForASecond() {
   waitSeconds(6);
   resetRuler(pruler);
}

task measureEncoders() {
   while (true) {
      leftEnc = getLeftTicks(pruler);
      rightEnc = getRightTicks(pruler);
      driveIn = getDriveTicks(pruler);
      rotateIn = getRotateTicks(pruler);
      swingIn = getSwingTicks(pruler);
   }
}
