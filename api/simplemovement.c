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

// functions without power arguments

void driveFW() {
	setMovement(DEFAULT_MOTOR_POWER, 0);
}

void driveBW() {
	setMovement(-DEFAULT_MOTOR_POWER, 0);
}

void rotateCW() {
   setMovement(0, DEFAULT_MOTOR_POWER/2);
}

void rotateCCW() {
	setMovement(0, -DEFAULT_MOTOR_POWER);
}

void swingFW(byte direction) {
	swing(direction, DEFAULT_MOTOR_POWER);
}

void swingBW(byte direction) {
	swing(direction, -DEFAULT_MOTOR_POWER);
}

// movement for time, with power arguments
void driveSeconds(float secs, byte power) {
	drive(power);
	waitSeconds(secs);
	halt();
}

void rotateSeconds(float secs, byte power) {
	rotate(power);
	waitSeconds(secs);
	halt();
}

void swingSeconds(float secs, byte direction, byte power) {
	swing(direction, power);
	waitSeconds(secs);
	halt();
}

// movement for time, without power argument

void driveSecondsFW(float secs) {
	driveFW();
	waitSeconds(secs);
	halt();
}

void driveSecondsBW(float secs) {
	driveBW();
	waitSeconds(secs);
	halt();
}

void rotateSecondsCW(float secs) {
	rotateCW();
	waitSeconds(secs);
	halt();
}

void rotateSecondsCCW(float secs) {
	rotateCCW();
	waitSeconds(secs);
	halt();
}

void swingSecondsFW(float secs, byte direction) {
	swingFW(direction);
	waitSeconds(secs);
	halt();
}

void swingSecondsBW(float secs, byte direction) {
	swingBW(direction);
	waitSeconds(secs);
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

// movement for inches, with no power argument

void driveInchesFW(float inches) {
	driveInches(inches, DEFAULT_MOTOR_POWER);
}

void driveInchesBW(float inches) {
	driveInches(inches, DEFAULT_MOTOR_POWER);
}

void rotateDegreesCW(float degrees) {
	rotateDegrees(degrees, DEFAULT_MOTOR_POWER);
}

void rotateDegreesCCW(float degrees) {
	rotateDegrees(degrees, -DEFAULT_MOTOR_POWER);
}

void swingDegreesFW(float degrees, byte direction) {
	swingDegrees(degrees, direction, DEFAULT_MOTOR_POWER);
}

void swingDegreesBW(float degrees, byte direction) {
	swingDegrees(degrees, direction, -DEFAULT_MOTOR_POWER);
}
