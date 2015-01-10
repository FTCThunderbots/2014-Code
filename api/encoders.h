// encoders.h
// Header file for encoders.c
#define ENCODERS_INCLUDEGUARD

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

//#warn "LEFT ENCODER WIRE BROKE AT COMPETITION, MAY NOT WORK!"

#ifndef setting_noEncoders

#define leftEnc1 nMotorEncoder[leftmotor_1]
#define rightEnc1 nMotorEncoder[rightmotor_1]

#ifndef setting_twoEncoders // there are four encoders
#define leftEnc2 nMotorEncoder[leftmotor_2]
#define rightEnc2 nMotorEncoder[rightmotor_2]
#else // only two encoders
#define leftEnc2 nMotorEncoder[leftmotor_1]
#define rightEnc2 nMotorEncoder[rightmotor_1]
#endif

#else //setting_noEncoders is defined

#define leftEnc1 0
#define rightEnc1 0
#define leftEnc2 0
#define rightEnc2 0

#endif

void resetEncoders();

// Unit conversions
int degreesToRotateTicks(float degrees);
int degreesToSwingTicks(float degrees);
int degreesToRawTicks(float degrees);
float rotateTicksToDegrees(long ticks);
float swingTicksToDegrees(long ticks);
float rawTicksToDegrees(long ticks);
int inchesToDriveTicks(float inches);
float driveTicksToInches(long ticks);
int centimetersToDriveTicks(float centimeters);
float driveTicksToCentimeters(long ticks);

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif
