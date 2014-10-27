// simplemovement.h
// Header file for simplemovement.c

#define SIMPLEMOVEMENT_INCLUDEGAURD

#ifndef MOVEMENT_INCLUDEGAURD
#include "movement.c"
#endif

void drive(byte power);
void strafe(byte power);
void rotate(byte power);
void swing(byte direction, byte power);
void moveDiagonal(byte vector, byte power);

//Need to be implemented
//void driveTicks(long ticks, byte power);
//void driveIn(byte dist, byte power);
//void driveCm(byte dist, byte power);
//void driveSec(byte sec, byte power);

//void strafeTicks(long ticks, byte power);
//void strafeIn(byte dist, byte power);
//void strafeCm(byte dist, byte power);
//void straftSec(byte sec, byte power);

//void rotateTicks(long ticks, byte power);
//void rotateDeg(byte degs, byte power);
//void rotateRad(float rads, byte power);
//void rotateSec(byte sec, byte power);

//void swingTicks(long ticks, byte direction, byte power);
//void swingDeg(byte degs, byte direction, byte power);
//void swingRad(float rads, byte direction, byte power);
//void swingSec(byte sec, byte direction, byte power);

//Other ideas:
//void moveDiagonalTicks(long ticks, byte vector, byte power);
//void moveDiagonalIn(byte dist, byte vector, byte power);
//void moveDiagonalCm(byte dist, byte vector, byte power);
//void moveDiagonalSec(byte sec, byte vector, byte power);

//Low priority: (Daniel's ideas)
//void turnSpiral(byte power, byte distance, byte deg);

// Deprecated and should probs remove:
void rotateDegWithCompass(int degs, byte power);
void rotateRadWithCompass(float rads, byte power)