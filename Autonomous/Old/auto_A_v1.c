#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     infrared,        sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightmotor_1,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     leftmotor_2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     rightmotor_2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     lift1,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     lift2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    bucket,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    pin,                  tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)

/*#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
*/

#define setting_twoEncoders

#include "../api/api.c"

// This program will drive off the ramp, pick up a goal, and carry it to the parking zone



task main() {
	initializeAPI();
	waitForStart();
	setMovementFromJoystick_old(-50, 0);
	nMotorEncoder[leftmotor_1] = 0;
	while (nMotorEncoder[leftmotor_1] > inchesToDriveTicks(96)) {setMovementFromJoystick_old(-50, 0); wait1Msec(10); nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
	setMovementFromJoystick_old(0, 0);
	wait1Msec(3000);
	setMovementFromJoystick_old(0, -50);
	nMotorEncoder[leftmotor_1] = 0;
	while (nMotorEncoder[leftmotor_1] > (8.5*(PI/2)/(4*PI))) {setMovementFromJoystick_old(0, -50); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
	setMovementFromJoystick_old(0, 0);
	wait1Msec(3000);
	setMovementFromJoystick_old(-50, 0);
	nMotorEncoder[leftmotor_1] = 0;
	while (nMotorEncoder[leftmotor_1] > inchesToDriveTicks(24)) {setMovementFromJoystick_old(-50, 0); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
	setMovementFromJoystick_old(0, 0);
	wait1Msec(3000);
	setMovementFromJoystick_old(0, 50);
	nMotorEncoder[leftmotor_1] = 0;
	while (nMotorEncoder[rightmotor_1] > -8.5*(PI/2)/(4*PI)) {setMovementFromJoystick_old(0, 50); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
	setMovementFromJoystick_old(0, 0);
	wait1Msec(3000);
	setMovementFromJoystick_old(-50, 0);
	nMotorEncoder[leftmotor_1] = 0;
	while (nMotorEncoder[leftmotor_1] > inchesToDriveTicks(12)) {setMovementFromJoystick_old(-50, 0); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
	setMovementFromJoystick_old(0, 0);
	setMovementFromJoystick_old(50, 0);
	nMotorEncoder[leftmotor_1] = 0;
	while (nMotorEncoder[leftmotor_1] > inchesToDriveTicks(120)) {setMovementFromJoystick_old(50, 0); wait1Msec(10);nxtDisplayCenteredBigTextLine(5, "%d", nMotorEncoder[leftmotor_1]);}
	setMovementFromJoystick_old(0, 0);
	/*driveInches(12*10); // 10 feet = 12*10 inches
	rotateDeg(180); // could equally be -180*/
	
	/*** Pick up the goal right here ***/
	
	/*driveInches(12*4); //just guessing here
	rotateDeg(30);
	driveInches(12*4); //still guessing*/
}
