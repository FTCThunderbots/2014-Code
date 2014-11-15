// simplemovement.c
// Contains very basic movement functions
// All functions are wrappers of functions in movement

#include "simplemovement.h"

//look in header for functions that need implementations

void stop() {
	setMovement(0,0,0);
}

void drive(byte power) {
	setMovement(power, 0, 0);
}

void drive() {
   setMovement(DEFAULT_MOTOR_POWER, 0, 0);
}

void strafe(byte power) {
	setMovement(0, power, 0);
}

void strafe() {
   setMovement(0, DEFAULT_MOTOR_POWER, 0);
}

void rotate(byte power) {
	setMovement(0, 0, power);
}

void rotate() {
   setMovement(0, 0, DEFAULT_MOTOR_POWER);
}

void swing(byte direction, byte power) {
	// direction: - for left, + or zero for right;
	direction = direction >=0 ? 1 : -1;
	setMovement(power, 0, direction * power);
}

void swing(byte direction) {
   swing(direction, DEFAULT_MOTOR_POWER);
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

void traverse(byte vector) {
   traverse(vector, DEFAULT_MOTOR_POWER);
}

void stopSeconds(float secs) {
   stop();
   waitSeconds(secs);
}

void driveSeconds(float secs, byte power) {
   drive(power);
   waitSeconds(secs);
   stop();
}

void driveSeconds(float secs) {
   drive();
   waitSeconds(secs);
   stop();
}

void strafeSeconds(float secs, byte power) {
   strafe(power);
   waitSeconds(secs);
   stop();
}

void strafeSeconds(float secs) {
   strafe();
   waitSeconds(secs);
   stop();
}

void rotateSeconds(float secs, byte power) {
   rotate(power);
   waitSeconds(secs);
   stop();
}

void rotateSeconds(float secs) {
   rotate();
   waitSeconds(secs);
   stop();
}

void swingSeconds(float secs, byte direction, byte power) {
   swing(direction, power);
   waitSeconds(secs);
   stop();
}

void swingSeconds(float secs, byte direction) {
   swing(direction);
   waitSeconds(secs);
   stop();
}

void traverseSeconds(float secs, byte vector, byte power) {
   traverse(vector, power);
   waitSeconds(secs);
   stop();
}

void traverseSeconds(float secs, byte vector) {
   traverse(vector);
   waitSeconds(secs);
   stop();
}

void rotateDegWithCompass(int degs, byte power) {
	int startFacing = getCompassValue();
	setMovement(0, 0, power);
	while(getCompassValue() != (startFacing + degs) % 360) {}
	// this probably will not work; ask Zach O. for more details.
	stop();
}
