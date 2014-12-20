// simplemovement.h
// Header file for simplemovement.c

#define SIMPLEMOVEMENT_INCLUDEGUARD

#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif

#ifndef MOVEMENT_INCLUDEGUARD
#include "movement.c"
#endif

#ifndef SENSORS_INCLUDEGUARD
#include "sensors.c"
#endif

//movement with power
void halt();
void drive(byte power);
void rotate(byte power);
void swing(byte direction, byte power);

//movement without power
void driveFW();
void driveBW();
void rotateCW();
void rotateCCW();
void swingFW(byte direction);
void swingBW(byte direction);

//movement for seconds with power
void driveSeconds(float secs, byte power);
void rotateSeconds(float secs, byte power);
void swingSeconds(float secs, byte direction, byte power);

//movement for seconds without power
void driveSecondsFW(float secs);
void driveSecondsBW(float secs);
void rotateSecondsCW(float secs);
void rotateSecondsCCW(float secs);
void swingSecondsFW(float secs, byte direction);
void swingSecondsBW(float secs, byte direction);

//movement for inches with power
void driveInches(float inches, byte power);
void rotateDegrees(float degrees, byte power);
void swingDegrees(float degrees, byte direction, byte power);

//movement for inches without power
void driveInchesFW(float inches);
void driveInchesBW(float inches);
void rotateDegreesCW(float degrees);
void rotateDegreesCCW(float degrees);
void swingDegreesFW(float degrees, byte direction);
void swingDegreesBW(float degrees, byte direction);
