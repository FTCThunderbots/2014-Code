// encoders.h
// Header file for encoders.c
#define ENCODERS_INCLUDEGUARD

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

// Accessing encoder values
#ifndef setting_noEncoders // there are encoders
	#define getEncoder_left1() nMotorEncoder[leftmotor_1]
	#define getEncoder_right1() nMotorEncoder[rightmotor_1]
	#ifdef setting_twoEncoders // there are only two encoders
		#define getEncoder_left2() nMotorEncoder[leftmotor_1]
		#define getEncoder_right2() nMotorEncoder[rightmotor_1]
	#else // there are four encoders
		#define getEncoder_left2() nMotorEncoder[leftmotor_2]
		#define getEncoder_right2() nMotorEncoder[rightmotor_2]
	#endif
#else // there are no encoders
	#define getEncoder_left1() 0
	#define getEncoder_right1() 0
	#define getEncoder_left2() 0
	#define getEncoder_right2() 0
#endif

// Setting encoder values
// I hope we never have to use these, but they're here just in case. (Zach)
#define setEncoder_left1(val) nMotorEncoder[leftmotor_1]=val
#define setEncoder_right1(val) nMotorEncoder[rightmotor_1]=val
#ifdef setting_twoEncoders
#define setEncoder_left2(val) nMotorEncoder[leftmotor_1]=val
#define setEncoder_right2(val) nMotorEncoder[rightmotor_1]=val
#else
#define setEncoder_left2(val) nMotorEncoder[leftmotor_2]=val
#define setEncoder_right2(val) nMotorEncoder[rightmotor_2]=val
#endif

void resetEncoders();

// Encoder get/set shortcuts. Useful for iterators?
long getEncoder(string name);
void setEncoder(string name, long val);

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
