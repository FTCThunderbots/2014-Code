// simplemovement.c
// Contains very basic movement functions
// All functions are wrappers of functions in movement

#include "simplemovement.h"

//look in header for functions that need implementations

void halt() {
	setMovement(0,0,0);
}

void drive(byte power) {
	setMovement(power, 0, 0);
}

void strafe(byte power) {
	setMovement(0, power, 0);
}

void rotate(byte power) {
	setMovement(0, 0, power);
}

void swing(byte direction, byte power) {
	// direction: - for left, + or zero for right;
	direction = direction >=0 ? 1 : -1;
	setMovement(power, 0, direction * power);
}

void traverse(byte vector, byte power) {
	// vector is 0 to 3, with 0 being straight forward, and 3 being back/left
	// use negative power to move in any of the other four directions

	if (vector % 8 > 3)
		power = -power;
	vector = vector % 4;

	//consider using pythagorean theorem to make sure overall speed is equal in all directions with a constant power
	byte drive = 1;
	byte strafe = 1;
	if (power < 0)
		strafe = -1;
	if (vector == 0)
		strafe = 0;
	if (vector == 2)
		drive = 0;
	if (vector == 3)
		drive = -1;

	setMovement(power * drive, power * strafe, 0);
}

// functions without power arguments

void driveFW() {
   setMovement(DEFAULT_MOTOR_POWER, 0, 0);
}

void driveBW() {
   setMovement(-DEFAULT_MOTOR_POWER, 0, 0);
}

void strafeR() {
	setMovement(0, DEFAULT_MOTOR_POWER, 0);
}

void strafeL() {
	setMovement(0, -DEFAULT_MOTOR_POWER, 0);
}

void rotateCW() {
   setMovement(0, 0, DEFAULT_MOTOR_POWER);
}

void rotateCCW() {
   setMovement(0, 0, -DEFAULT_MOTOR_POWER);
}


void swingFW(byte direction) {
   swing(direction, DEFAULT_MOTOR_POWER);
}

void swingBW(byte direction) {
   swing(direction, -DEFAULT_MOTOR_POWER);
}

void traverse(byte vector) {
   traverse(vector, DEFAULT_MOTOR_POWER);
}

// movement for time, with power arguments

void haltSeconds(float secs) {
   halt();
   waitSeconds(secs);
}

void driveSeconds(float secs, byte power) {
   drive(power);
   waitSeconds(secs);
   halt();
}

void strafeSeconds(float secs, byte power) {
   strafe(power);
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

void traverseSeconds(float secs, byte vector, byte power) {
   traverse(vector, power);
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

void strafeSecondsR(float secs) {
   strafeR();
   waitSeconds(secs);
   halt();
}

void strafeSecondsL(float secs) {
   strafeL();
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

void traverseSeconds(float secs, byte vector) {
   traverse(vector);
   waitSeconds(secs);
   halt();
}

// movement for inches, with power argument
void driveInches(float inches, byte power) {
   drive(power);
   waitDriveInches(inches);
   halt();
}

void strafeInches(float inches, byte power) {
	strafe(power);
	waitStrafeInches(inches);
	halt();
}

void rotateDegrees(float degrees, byte power) {
	rotate(power);
	waitRotateDegrees(degrees);
	halt();
}

void swingDegrees(float degrees, byte direction, byte power) {
	swing(direction, power);
	waitSwingDegrees(degrees);
	halt();
}

// movement for inches, with no power argument

void driveInchesFW(float inches) {
   driveFW();
   waitDriveInches(inches);
   halt();
}

void driveInchesBW(float inches) {
   driveBW();
   waitDriveInches(inches);
   halt();
}

void strafeInchesR(float inches) {
	strafeR();
	waitStrafeInches(inches);
	halt();
}

void strafeInchesL(float inches) {
	strafeL();
	waitStrafeInches(inches);
	halt();
}

void rotateDegreesCW(float degrees) {
	rotateCW();
	waitRotateDegrees(degrees);
	halt();
}

void rotateDegreesCCW(float degrees) {
	rotateCCW();
	waitRotateDegrees(degrees);
	halt();
}

void swingDegreesFW(float degrees, byte direction) {
	swingFW(direction);
	waitSwingDegrees(degrees);
	halt();
}

void swingDegreesBW(float degrees, byte direction) {
	swingBW(direction);
	waitSwingDegrees(degrees);
	halt();
}

void grab() {
	servo[grab] = GRAB_POS;
}

// deprecated: probably not as precise as it could be
// also, in it's current form, problems may arise if passing arguments more than 36
void rotateDegWithCompass(int degs, byte power) {
	int startFacing = getCompassValue();
	setMovement(0, 0, power);
	while(getCompassValue() != (startFacing + degs) % 360) {}
	// this probably will not work; ask Zach O. for more details.
	halt();
}
