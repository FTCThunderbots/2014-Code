// simplemovement.h
// Header file for simplemovement.c

#include "api.h"

void drive(int power);
void strafe(int power);
void rotate(int power);
void swingTurn(int direction, int power);
void moveDiagonal(int vector, int power);

//Need to be implemented
void driveTicks(int ticks, int power);
void driveIn(int dist, int power);
void driveCm(int dist, int power);

void strafeTicks(int ticks, int power);
void strafeIn(int dist, int power);
void strafeCm(int dist, int power);

void rotateTicks(int ticks, int power);
void rotateDeg(int degs, int power);
void rotateRad(int rads, int power);

//Other ideas:
void swingTurnTicks(int ticks, int direction, int power);
void swingTurnDeg(int degs, int directions, int power);
void swingTurnRad(int rads, int directions, int power);

void moveDiagonalTicks(int dist, int vector, int power);
void moveDiagonalIn(int dist, int vector, int power);
void moveDiagonalCm(int dist, int vector, int power);

//Low priority: (Daniel's ideas)
void turnSpiral(byte power, int distance, int deg);
