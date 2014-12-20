// encoders.h
// Header file for encoders.c
#define ENCODERS_INCLUDEGUARD

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

#define leftEnc1 nMotorEncoder[leftmotor_1]
#define rightEnc1 nMotorEncoder[rightmotor_1]

#ifndef setting_twoEncoders // there are four encoders
#define leftEnc2 nMotorEncoder[leftmotor_2]
#define rightEnc2 nMotorEncoder[rightmotor_2]
#else // only two encoders
#define leftEnc2 nMotorEncoder[leftmotor_1]
#define rightEnc2 nMotorEncoder[rightmotor_1]
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

//actual measurement code
void moveFor(int ticks);
void swingLeftFor(int ticks);
void swingRightFor(int ticks);
