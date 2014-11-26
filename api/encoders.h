// encoders.h
// Header file for encoders.c
#define ENCODERS_INCLUDEGUARD

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

// Trial code here: we'll discuss if we want to keep it
#define leftEnc1 nMotorEncoder[leftmotor_1]
#define rightEnc1 nMotorEncoder[rightmotor_1]
#ifndef setting_twoEncoders // there are four encoders
#define leftEnc2 nMotorEncoder[leftmotor_2]
#define rightEnc2 nMotorEncoder[rightmotor_2]
#else // only two encoders
#define leftEnc2 nMotorEncoder[leftmotor_1]
#define rightEnc2 nMotorEncoder[rightmotor_1]
#endif

// Encoder get/set shortcuts. Useful for iterators?
void resetEncoders();

// Unit conversions
long degreesToRotateTicks(float degrees);
long degreesToSwingTicks(float degrees);
float rotateTicksToDegrees(long ticks);
float swingTicksToDegrees(long ticks);
long inchesToDriveTicks(float inches);
long inchesToStrafeTicks(float inches);
float driveTicksToInches(long ticks);
float strafeTicksToInches(long ticks);
long centimetersToDriveTicks(float centimeters);
long centimetersToStrafeTicks(float centimeters);
float driveTicksToCentimeters(long ticks);
float strafeTicksToCentimeters(long ticks);

/* 	You said to "make it prettier"

	  /-_-\
	 /  /  \
	/  /    \
	\  \    /
	 \__\__/
	    \\
	    -\\    ____
	      \\  /   /
	____   \\/___/
	\   \ -//
	 \___\//-
	    -//
	     \\
	     //
	    //-
	  -//
	  //
	  \\
	   \\
*/
