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


#define XCOORD 0
#define ZCOORD 1
#define DEG	2

float x = 0.0, z = 0.0;			// Zach O please stop freaking out over this, these are two VERY similar variables.
float orientation = 0.0;
float changeCoord = 0.0;
float circumference = 4 * PI;

#define setting_twoMotors
#define DEBUG_STREAM_ON
#define debugStreamLine1	x
#define debugStreamType1 "%.3f"
#define debugStreamLine2	z
#define debugStreamType2 "%.3f"
#define debugStreamLine3	orientation
#define debugStreamType3 "%.3f"

#ifndef UNIT_CONVERTER
#define UNIT_CONVERTER	"%.2f"
#endif

#include "unit_converter.c"
#include "../api/api.c"

float getCoordinateValue();

float updateX(float degrees, float distanceTraveled) {
	return (float)(x + sin(degrees) * distanceTraveled); //returns float
}

float updateZ(float degrees, float distanceTraveled) {
	return (float)(z + cos(degrees) * distanceTraveled);
}

float getOrientation(float degrees) {
	// will return off a base of 4
	// orientation will always be equal to theta, and will return in DEGREES
	// It is up to the programmer to deal with the degrees
	return (float)(degrees * (180 / PI));
}

// deleted updateCoords() due to bugginess and no really useful implementation

float getCoordinateValue(int value) {
	if (value == 0) {
			return x;
	} else if (value == 1) {
			return z;
	} else if (value == 2) {
			return orientation;
	}
	return -1;
}

// 1 MPH for one sec 5280 FT/Hour divide by 60^2= 5280/3600
// approx. 1.47 ft/second @ 1 MPH would be useful to know how much the robot actually moves in one second
// That will equal the amount the robot moves in one second. (Assuming batteries are full)

void gotoCoordinates(float newX, float newZ, float newOrientation) {	
	// start loop
	/*
	*Thanks to the API most of the movement code was simplified so now
	*it has been reduced to loops and float values
	*/
	if (orientation > 80 && orientation < 100) {
	
	} else {
		while (orientation < 80 || orientation > 100) {
			int orientationRotation = (int)(orientation * 1.46 / 360 + 90);
			rotateSeconds(1);
		}
	}
	
	if (newX < x) {
		while (newX < x) {
			driveForSecondsFW(0.56);
			updateX(degreesToRadians(orientation), 1.0);
		}
	} else {
		while (newX > x) {
			driveForSecondsBW(0.56);
			updateX(degreesToRadians(orientation), -1.0);
		}
	}
	
	if (orientation > 190 && orientation < 170) {
	
	} else {
		while (orientation < 80 || orientation > 100) {
			int orientationRotation = (int)(orientation * 1.46 / 360 + 90);
			rotateSeconds(1);
		}
	}
	
	if (newZ < z) {
		while (newZ < z) {
			driveForSecondsFW(0.56);
			updateZ(degreesToRadians(orientation), 1.0);
		}
	} else {
		while (newZ > z) {
			driveForSecondsBW(0.56);
			updateZ(degreesToRadians(orientation), -1.0);
		}
	}
	
	if (orientation > newOrientation+10 && orientation < newOrientation-10) {
	
	} else {
		while (orientation < newOrientation+10 || orientation > newOrientation-10) {
			int orientationRotation = (int)(orientation * 1.46 / 360 + 90);
			rotateSeconds(1);
		}
	}
}