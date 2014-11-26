// encoders.h
// Header file for encoders.c
#define ENCODERS_INCLUDEGUARD

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

// Encoder get/set shortcuts. Useful for iterators?
void resetEncoders();

// Unit conversions
long degreesToTicks(float degrees);
long degreesToRotateTicks(float degrees);
long degreesToSwingTicks(float degrees);
float ticksToDegrees(long ticks);
float rotateTicksToDegrees(long ticks);
float swingTicksToDegrees(long ticks);
long inchesToTicks(float inches);
long inchesToDriveTicks(float inches);
long inchesToStrafeTicks(float inches);
float ticksToInches(long ticks);
float driveTicksToInches(long ticks);
float strafeTicksToInches(long ticks);
long centimetersToTicks(float centimeters);
long centimetersToDriveTicks(float centimeters);
long centimetersToStrafeTicks(float centimeters);
float ticksToCentimeters(long ticks);
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
