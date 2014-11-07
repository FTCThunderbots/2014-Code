// encoders.h
// Header file for encoders.c
#define ENCODERS_INCLUDEGAURD

//function macros
#define setEncoder(name,val) nMotorEncoder[name]=val

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
