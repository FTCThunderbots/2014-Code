/* encoders.h | Header file for encoders.c
 * Copyright (C) 2015 Thunderbots-5604
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */
 
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
