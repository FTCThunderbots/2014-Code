// encoders.c
// Contains code for accessing encoder values at the lowest possible level

#include "encoders.h"

// Unit conversions

void resetEncoders() {
	leftEnc1 = 0;
	leftEnc2 = 0;
	rightEnc1 = 0;
	rightEnc2 = 0;
}

// degrees to ticks
int degreesToRotateTicks(float degrees) {
	return (int)ENCODER_TICKS_PER_ROTATE_DEGREE * degrees;
}

int degreesToSwingTicks(float degrees) {
	return (int)ENCODER_TICKS_PER_SWING_DEGREE * degrees;
}

int degreesToRawTicks(float degrees) {
	//convert raw degrees into ticks for simple rotating mechanisms
	return (int)ENCODER_TICKS_PER_DEGREE * degrees;
}

// ticks to degrees
float rotateTicksToDegrees(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_ROTATE_DEGREE;
}

float swingTicksToDegrees(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_SWING_DEGREE;
}

float rawTicksToDegrees(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_DEGREE;
}

// inches to ticks
int inchesToDriveTicks(float inches) {
	return (int)ENCODER_TICKS_PER_DRIVE_INCH * inches;
}

// ticks to inches
float driveTicksToInches(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_DRIVE_INCH;
}

// centimeters to ticks
int centimetersToDriveTicks(float centimeters) {
	return inchesToDriveTicks(cmToIn(centimeters));
}

// ticks to centimeters
float driveTicksToCentimeters(long ticks) {
	return inToCm(driveTicksToInches(ticks));
}

void moveFor(int ticks, int speed) { //speed is positive for rotating
	//this will work for rotating in place and linear driving (forwards and backwards)
	//might also work for strafing
	resetEncoders();
	ClearTimer(T1);
	if (sgn(motor[leftmotor_1]) != sgn(motor[rightmotor_1])) //we are rotating
		while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {correctRotate(speed);}
	else //we are driving
		while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {correctLinear(speed);}
}

void swingFor(int ticks, int speed) {
   resetEncoders();
	 #ifdef setting_twoMotors
   while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/2 < abs(ticks)) {}
   #else
   while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/2 < abs(ticks)) {correctSwing(speed);}
   #endif
}
