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

// ticks to degrees
float rotateTicksToDegrees(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_ROTATE_DEGREE;
}

float swingTicksToDegrees(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_SWING_DEGREE;
}

// inches to ticks
int inchesToDriveTicks(float inches) {
	return (int)ENCODER_TICKS_PER_DRIVE_INCH * inches;
}

int inchesToStrafeTicks(float inches) {
	return 	(int)ENCODER_TICKS_PER_STRAFE_INCH * inches;
}

// ticks to inches
float driveTicksToInches(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_DRIVE_INCH;
}

float strafeTicksToInches(long ticks) {
	return (float)ticks / ENCODER_TICKS_PER_STRAFE_INCH;
}

// centimeters to ticks
int centimetersToDriveTicks(float centimeters) {
	return inchesToDriveTicks(cmToIn(centimeters));
}

int centimetersToStrafeTicks(float centimeters) {
	return inchesToStrafeTicks(cmToIn(centimeters));
}

// ticks to centimeters
float driveTicksToCentimeters(long ticks) {
	return inToCm(driveTicksToInches(ticks));
}

float strafeTicksToCentimeters(long ticks) {
	return inToCm(strafeTicksToInches(ticks));
}

void moveFor(int ticks) {
	//this will work for rotating in place and linear driving (forwards and backwards)
	//might also work for strafing
	resetEncoders();
	while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {/*wait*/}
}

void swingLeftFor(int ticks) {
	//incase you could not tell, this is for swinging to the left
	resetEncoders();
	while ((abs(rightEnc1) + abs(rightEnc2))/2 < abs(ticks)) {/*wait*/}
}

void swingRightFor(int ticks) {
	//incase you could not tell, this is for swinging to the right
	resetEncoders();
	while ((abs(leftEnc1) +abs(leftEnc2))/2 < abs(ticks)) {/*wait*/}
}
