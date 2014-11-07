#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     infrared,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     Left,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     Right,         tmotorTetrix, openLoop, encoder)
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

#define STOP stopFor1Sec()
#define setting_twoMotors

#include "../api/api.c"

void stopFor1Sec() {
	stop();
	wait1Msec(1000);
}

task main() {
	initializeAPI();

	//drive:
	//drive foward for a second
	drive(100);
	wait1Msec(1000);
	STOP;

	//drive back
        drive(-100);
        wait1Msec(1000);
        STOP;

	//rotation:
	//rotate for one second
	rotate(100);
	wait1Msec(1000);
	STOP;

	//rotate back
        rotate(-100);
        wait1Msec(1000);
        STOP;

	//strafe:
	/*//strafe for one second
	strafe(100);
	wait1Msec(1000);
	STOP;

	//strafe back
	strafe(-100);
	wait1Msec(1000);
	STOP;*/

	//swing turn:
	//swing left for a second
	swing(-5, 100);
	wait1Msec(1000);
	STOP;

	//swing right for a second
        swing(7, 100);
        wait1Msec(1000);
        STOP;

	//go back
	swing(-5, -100);
        wait1Msec(1000);
        STOP;

        swing(7, -100);
        wait1Msec(1000);
        STOP;

	//diagonals: (should form a X pattern)
	//not implemented (requires mecanum drive)
	//Zach, please explain the moveDiagonal function!
	//I have no idea as to what it is doing or trying to do
	//in your comments you say that passing 0 will move straight foward
	//STRAIGHT FOWARD IS NOT DIAGONAL!!!
	//please explain this method.

	//rotating degrees with the compass sensor
	//rotateDegWithCompass(90, 100);
}
