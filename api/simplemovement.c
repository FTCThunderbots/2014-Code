// simplemovement.c
// Contains very basic movement functions
// All functions are wrappers of functions in movement

#include "simplemovement.h"

//look in header for functions that need implementations

void halt() {
	setMovement(0,0);
}

void drive(byte power) {
	setMovement(power, 0);
}

void rotate(byte power) {
	setMovement(0, power);
}

void swing(byte direction, byte power) {
	// direction: - for left, + or zero (don't use zero) for right;
	setMovement(power, sgn(direction) * power);
}

// movement for time, with power arguments
void driveSeconds(float secs, byte power) {
	drive(power);
	ClearTimer(T1);
	while(time1[T1] < abs(secs)*1000) {}
	halt();
}

void rotateSeconds(float secs, byte power) {
	rotate(power);
	ClearTimer(T1);
	while(time1[T1] < abs(secs)*1000) {}
	halt();
}

void swingSeconds(float secs, byte direction, byte power) {
	swing(direction, power);
	ClearTimer(T1);
	while(time1[T1] < abs(secs)*1000) {}
	halt();
}

// movement for inches, with power argument
void driveInches(float inches, byte power, bool usePID) {
	drive(power);
	moveFor(inchesToDriveTicks(inches), power, usePID);
	halt();
}

void rotateDegrees(float degrees, byte power, bool usePID) {
	rotate(power);
	moveFor(degreesToRotateTicks(degrees), power, usePID);
	halt();
}

void swingDegrees(float degrees, byte direction, byte power, bool usePID) {
	swing(direction, power);
	swingFor(degreesToSwingTicks(degrees), direction, power, usePID);
	halt();
}
