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
// #include statements

#define XCOORD 0
#define ZCOORD 1
#define DEG	2

float x = 0.0, z = 0.0;
float orientation = 0.0;
float changeCoord = 0.0;
float circumference = 4 * PI;

#define setting_twoMotors
#define DEBUG_STREAM_ON
#define debugStreamLine1	x
#define debugStreamLine2	z
#include "unit_converter.c"
#include "../api/api.c"
//to drive say
//drive(100)

//to turn, say
//rotate(100)
/*
int declareAnyVariableHere = 0;
#define DEBUG_STREAM_ON
#define debugStreamLine1 declareAnyVariableHere
#define debugStreamLine2 anyOtherVariable
//up to 8
*/

void turn45(bool right);

static float updateX(float degrees, float distanceTraveled) {
	return (float)(x + sin(degrees) * distanceTraveled); //remove cast
}

static float updateZ(float degrees, float distanceTraveled) {
	return (float)(z + cos(degrees) * distanceTraveled);
}

float getOrientation(float degrees) {
	// will return off a base of 4
	// orientation will always be equal to theta, and will return in DEGREES
	// It is up to the programmer to deal with the degrees
	return (float)(degrees * (180 / PI));
}

void updateCoords(float degrees, length_t CIRCUM_TYPE) {
		/*
			1. Divide ticks by 1440 then multiply by circumference (Gives you how far it moved in the units
			you have used for circumference.
			2. Convert the units to feet.
		*/
		float ticks = nMotorEncoder[leftmotor_1]; /* Will remain NULL until motor is known.*/
		ticks += nMotorEncoder[rightmotor_1];
		ticks /= 2;

		float changeCoord = (ticks / 1440) * convertUnits(INCHES, FEET, circumference);

		/*
		*First I take the degrees and convert to radians.
		*Next, I'll use sin(rad) += x
		*/

		degrees = degreesToRadians(degrees);
		float changedX = updateX(degrees, changeCoord);
		x += changedX;
		float changedZ = updateZ(degrees, changeCoord);
		z += changedZ;
		float changedOrientation = getOrientation(degrees);
		orientation = changedOrientation;

		// reset changeCoord
		changeCoord = 0.0;
}

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

void gotoCoordinates(float newX, float newZ, float newOrientation) {
	/*
		For now I will go in the following order:
			1.) I will go to the correct X value
			2.) Next the correct Z value
			3.) Finally rotate until orientation = newOrientation
	*/

	// code used to rotate robot to starting degrees goes here
	nMotorEncoder[leftmotor_1] = 0;
	nMotorEncoder[rightmotor_1] = 0;

	if (newX < x) {
		while (orientation >= -90 - 10 || orientation <= -90 + 10) {
			// Rotate robot
			turn45(true);
			updateCoords(45, INCHES);
		}
	} else {
		while (orientation >= 90 + 10 || orientation <= 90 - 10) {
			// Rotate robot
			turn45(false);
			updateCoords(45, INCHES);
		}
	}

	while (x < newX + 1 || x > newX - 1) {
		float ticks = nMotorEncoder[leftmotor_1]; /* Will remain NULL until motor is known.*/
		ticks += nMotorEncoder[rightmotor_1];
		ticks /= 2;
		changeCoord = (ticks / 1440) * convertUnits(INCHES, FEET, circumference);
		updateX(90, changeCoord);
		drive(50);
	}

	if (newZ < z) {
		while (orientation >= -180 - 10 || orientation <= -180 + 10) {
			// Rotate robot
			turn45(true);
			updateCoords(45, INCHES);
		}
	} else {
		while (orientation >= 180 + 10 || orientation <= 180 - 10) {
			// Rotate robot
			turn45(false);
			updateCoords(45, INCHES);
		}
	}

	nMotorEncoder[leftmotor_1] = 0;
	nMotorEncoder[rightmotor_1] = 0;

	while (z < newZ + 1 || z > newZ - 1) {
		float ticks = nMotorEncoder[leftmotor_1]; /* Will remain NULL until motor is known.*/
		ticks += nMotorEncoder[rightmotor_1];
		ticks /= 2;
		changeCoord = (ticks / 1440) * convertUnits(INCHES, FEET, circumference);
		updateZ(180, changeCoord);
		drive(50);
	}
}

void resetEncoders() {
	nMotorEncoder[leftmotor_1] = 0;
	nMotorEncoder[rightmotor_1] = 0;
}

void brake() {
	setMovement(0,0);
}
void turn45(bool right){ //true is right, false is left
	int power = 0;

	if (right){
		power = 100;
	}
	else{
		power = -100;
	}
	resetEncoders();
	motor[leftmotor_1] = power;
	motor[rightmotor_1] = -power;
	//wait1Msec(TURN45TIME);
	while ((abs(nMotorEncoder[leftmotor_1]) + abs(nMotorEncoder[rightmotor_1]))/2 < 645)
		wait1Msec(1);
	brake();
}
