// simplemovement.c
// Contains very basic movement functions
// All functions are wrappers of functions in movement

#include "simplemovement.h"

//look in header for functions that need implementations

void drive(byte power) {
	setMovement(power, 0, 0);
}

void strafe(byte power) {
	setMovement(0, power, 0);
}

void rotate(byte power) {
	setMovement(0, 0, power);
}

void halt() {
	setMovement(0,0,0);
}

void swingTurn(byte direction, byte power) {
	// direction: 0 for left, 1 for right;
	direction = direction == 0 ? -1 : 1;
	setMovement(power, 0, direction * power);
}

void moveDiagonal(byte vector, byte power) {
	// vector is 0 to 3, with 0 being straight forward, and 3 being back/left
	// use negative power to move in any of the other four directions

	//consider using pothagorean theorem to make sure overall speed is equal in all directions with a constant power
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

// should move to math.c
// or even better...
// TODO: create step function in math
int correctDegs(int degs) {
	int fullspins = degs/360;
	return degs-(360*fullspins)
}

void rotateDeg(int degs, byte power){
	#warn "Compass sensor is used in rotateDeg"
	//uses compass sensor
	int startFacing = SensorValue[compass];
	setMovement(0, 0, power);
	while(SensorValue[compass] != correctDegs(startFacing+degs)){}
	halt();
}

void rotateRad(int rads, byte power) {
	rotateDeg(radiansToDegrees(rads), power);
}

void rotateTicks(long ticks, byte power) {
#warn "rotateTicks is not implemented"
}

