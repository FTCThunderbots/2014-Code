// encoders.c
// Contains code for accessing encoder values at the lowest possible level

#include "encoders.h"

void resetEncoders() {
	setEncoder_left1(0);
	setEncoder_left2(0);
	setEncoder_right1(0);
	setEncoder_right2(0);
}

// Encoder get/set shortcuts. Useful for iterators?

long getEncoder(string name) {
   if (name == "left1")
      return getEncoder_left1();
   if (name == "left2")
      return getEncoder_left2();
   if (name == "right1")
      return getEncoder_right1();
   if (name == "right2")
      return getEncoder_right2();
   return -1;
}

void setEncoder(string name, long val) {
   if (name == "left1")
      setEncoder_left1(val);
   else if (name == "left2")
      setEncoder_left2(val);
   else if (name == "right1")
      setEncoder_right1(val);
   else if (name == "right2")
      setEncoder_right2(val);
}

// Unit conversions

// degrees to ticks
long degreesToTicks(float degrees) {
	return degreesToRotateTicks(degrees);
}

long degreesToRotateTicks(float degrees) {
	return ENCODER_TICKS_PER_ROTATE_DEGREE * degrees;
}

long degreesToSwingTicks(float degrees) {
	return ENCODER_TICKS_PER_SWING_DEGREE * degrees;
}

// ticks to degrees
float ticksToDegrees(long ticks) {
	return rotateTicksToDegrees(ticks);
}

float rotateTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_ROTATE_DEGREE;
}

float swingTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_SWING_DEGREE;
}

// inches to ticks
long inchesToTicks(float inches) {
	return inchesToDriveTicks(inches);
}

long inchesToDriveTicks(float inches) {
	return ENCODER_TICKS_PER_DRIVE_INCH * inches;
}

long inchesToStrafeTicks(float inches) {
	return 	ENCODER_TICKS_PER_STRAFE_INCH * inches;
}

// ticks to inches
float ticksToInches(long ticks) {
	return driveTicksToInches(ticks);
}

float driveTicksToInches(long ticks) {
	return ticks / ENCODER_TICKS_PER_DRIVE_INCH;
}

float strafeTicksToInches(long ticks) {
	return ticks / ENCODER_TICKS_PER_STRAFE_INCH;
}

// centimeters to ticks
long centimetersToTicks(float centimeters) {
	return centimetersToDriveTicks(centimeters);
}

long centimetersToDriveTicks(float centimeters) {
	return inchesToTicks(cmToIn(centimeters));
}

long centimetersToStrafeTicks(float centimeters) {
	return inchesToStrafeTicks(cmToIn(centimeters));
}

// ticks to centimeters
float ticksToCentimeters(long ticks) {
	return driveTicksToCentimeters(ticks);
}

float driveTicksToCentimeters(long ticks) {
	return inToCm(driveTicksToInches(ticks));
}

float strafeTicksToCentimeters(long ticks) {
	return inToCm(strafeTicksToInches(ticks));
}
