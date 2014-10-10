//simplemovement.c
//contains very basic movement functions
//all are wrappers of functions in movement

#include "simplemovement.h"
#include "movement.c"

//example:

void driveForward(int power) {
	//motor[mp] = power;
}

//NOT IMPLEMENTED YET:
void moveFoward(byte power, short distance/*We need to decide: cm or in?*/) {}
void moveStrafe(byte power, short distance/*We need to decide: cm or in?*/) {}
void turnInPlace(byte power, short deg) {}
void turnSwing(byte power, short deg) {}

//Low priority
//move in a spiral, like r = x in a polar graph
//variables may need changing
void turnSpiral(byte power, short distance/*We need to decide: cm or in?*/, short deg) {}
void moveDiagonal(char vect/*which diagonal?*/, byte power, short distance/*We need to decide: cm or in?*/) {}
