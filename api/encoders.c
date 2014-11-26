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
long degreesToRotateTicks(float degrees) {
	return ENCODER_TICKS_PER_ROTATE_DEGREE * degrees;
}

long degreesToSwingTicks(float degrees) {
	return ENCODER_TICKS_PER_SWING_DEGREE * degrees;
}

// ticks to degrees
float rotateTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_ROTATE_DEGREE;
}

float swingTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_SWING_DEGREE;
}

// inches to ticks
long inchesToDriveTicks(float inches) {
	return ENCODER_TICKS_PER_DRIVE_INCH * inches;
}

long inchesToStrafeTicks(float inches) {
	return 	ENCODER_TICKS_PER_STRAFE_INCH * inches;
}

// ticks to inches
float driveTicksToInches(long ticks) {
	return ticks / ENCODER_TICKS_PER_DRIVE_INCH;
}

float strafeTicksToInches(long ticks) {
	return ticks / ENCODER_TICKS_PER_STRAFE_INCH;
}

// centimeters to ticks
long centimetersToDriveTicks(float centimeters) {
	return inchesToTicks(cmToIn(centimeters));
}

long centimetersToStrafeTicks(float centimeters) {
	return inchesToStrafeTicks(cmToIn(centimeters));
}

// ticks to centimeters
float driveTicksToCentimeters(long ticks) {
	return inToCm(driveTicksToInches(ticks));
}

float strafeTicksToCentimeters(long ticks) {
	return inToCm(strafeTicksToInches(ticks));
}
