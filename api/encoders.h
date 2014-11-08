// encoders.h
// Header file for encoders.c
#define ENCODERS_INCLUDEGAURD

// Accessing encoder values
#define getEncoder_left1() nMotorEncoder[leftmotor_1]
#define getEncoder_right1() nMotorEncoder[rightmotor_1]
#ifdef setting_twoEncoders
#define getEncoder_left2() nMotorEncoder[leftmotor_1]
#define getEncoder_right2() nMotorEncoder[rightmotor_1]
#else
#define getEncoder_left2() nMotorEncoder[leftmotor_2]
#define getEncoder_right2() nMotorEncoder[rightmotor_2]
#endif

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
   if (name == "left2")
      setEncoder_left2(val);
   if (name == "right1")
      setEncoder_right1(val);
   if (name == "right2")
      setEncoder_right2(val);
}

// Unit conversions
long degreesToTicks(float degrees);
long degreesToTurnTicks(float degrees);
long degreesToSwingTicks(float degrees);
float ticksToDegrees(long ticks);
float turnTicksToDegrees(long ticks);
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
