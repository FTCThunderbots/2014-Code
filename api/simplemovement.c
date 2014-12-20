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
	// direction: - for left, + or zero for right;
	direction = sgn(direction);
	setMovement(power, direction * power);
}

// movement for time, with power arguments
void driveSeconds(float secs, byte power) {
	drive(power);
	int startTime = time1[T1];
	while(time1[T1] < startTime + secs*1000) { drive(power); }
	halt();
}

void rotateSeconds(float secs, byte power) {
	rotate(power);
	int startTime = time1[T1];
	while(time1[T1] < startTime + secs*1000) { rotate(power); }
	halt();
}

void swingSeconds(float secs, byte direction, byte power) {
	swing(direction, power);
	int startTime = time1[T1];
	while(time1[T1] < startTime + secs*1000) { swing(power); }
	halt();
}



// movement for inches, with power argument
void driveInches(float inches, byte power) {
	drive(power);
	moveFor(inchesToDriveTicks(inches));
	halt();
}

void rotateDegrees(float degrees, byte power) {
	rotate(power);
	moveFor(degreesToRotateTicks(degrees));
	halt();
}

void swingDegrees(float degrees, byte direction, byte power) {
	swing(direction, power);
	if (sgn(direction) == 1)
		swingRightFor(degreesToSwingTicks(degrees));
	else
		swingLeftFor(degreesToSwingTicks(degrees));
	halt();
}
