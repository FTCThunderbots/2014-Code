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

//*!!Re-written for this year's robot               !!*//

#include "coord_test.c"

// x, y, and z defined in coord_test.c
// default coordinates are x=0, z=0, orientation=90deg (PI/2 rad)

void testCoords() {
	gotoCoordinates(1, 0, 180);
	gotoCoordinates(0, 0, 0);
	gotoCoordinates(0, 1, 180);
	
	gotoCoordinates(0, 0, 0);
	
	x = getCoordinateValue(0);
	z = getCoordinateValue(1);
	orientation = getCoordinateValue(2);
}

task main()
{
	waitForStart();
	testCoords();
}
