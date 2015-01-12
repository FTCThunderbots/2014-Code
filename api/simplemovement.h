// simplemovement.h
// Header file for simplemovement.c

#define SIMPLEMOVEMENT_INCLUDEGUARD

#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif

#ifndef MOVEMENT_INCLUDEGUARD
#include "movement.c"
#endif

#ifndef PID_INCLUDEGUARD
#include "pid.c"
#endif

#ifndef SENSORS_INCLUDEGUARD
#include "sensors.c"
#endif

//movement with power
void halt();
void drive(byte power);
void rotate(byte power);
void swing(byte direction, byte power);

//movement for seconds with power
void driveSeconds(float secs, byte power);

void rotateSeconds(float secs, byte power);
void swingSeconds(float secs, byte direction, byte power);

//movement for inches with power
void driveInches(float inches, byte power);
void driveInches(float inches, byte power, int stopSeconds);
void rotateDegrees(float degrees, byte power);
void swingDegrees(float degrees, byte direction, byte power);
