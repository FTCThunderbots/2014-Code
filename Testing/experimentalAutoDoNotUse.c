#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     infrared,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     grab,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backboard,     tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define INFRARED infrared
#define setting_twoEncoders
//Configuration is current as of 1/01/15 4:54 PM

//USE DEFAULT CONFIG

#include "../api/api.c"
#include "../api/coord.c"
#include "../Testing/auto_instruction_reader.h"

/* Format: {mode, distance, power, pause}
 * Mode: either 'd' or 'r', for either drive or rotate
 * Distance: the first argument to the movement function
 * Power: the power argument to the movement function
 * Pause: the hundreds of milliseconds to pause after the action.
 *   leave at 0 for no delay or -1 to use the standard delay.
 */

byte actions[][4] = {{'d', 60, -stdPow, -1},
	{'r', 45, -stdPow, -1},
	{'d', 22, -stdPow, -1},
	{'r', 45, stdPow, -1},
	{'d', 16, -25, -1},
	{'d', 10, -15, 0}, //start task after this
	{'g', 0, 0, 1},
	{'d', 9, -10, 10},
	{'d', 60, stdPow, -1},
	{'r', 20, stdPow, 0}, //motor[conveyor] = 100
	{'d', 0, 0, -1}, //pause
	{'r', 180, stdPow, 0}
};

task grabTask();

task main()
{
	initializeAPI();
	initializeRobot();
	waitForStart();

	setDefaultCoords();      // Coordinate system values


	rotateWithOrientation(20, 50);
	motor[conveyor] = 100;
	wait1Msec(500);
	moveWithDirection(45, 50);
	wait1Msec(500);
	motor[conveyor] = 0;
	rotateWithOrientation(180, 50);
}

task grabTask() {
	motor[grab] = GRAB_MOTOR_SPEED/2;
	wait1Msec(GRAB_MOTOR_DOWN_TIME*2);
	motor[grab] = 0;
	isGoalGrabbed = true;
}
