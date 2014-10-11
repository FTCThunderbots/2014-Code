// simplemovement.c
// Contains very basic movement functions
// All functions are wrappers of functions in movement

#include "simplemovement.h"

//look in header for functions that need implementations

void drive(int power) {
	setMovement(power, 0, 0);
}

void strafe(int power) {
	setMovement(0, power, 0);
}

void rotate(int power) {
	setMovement(0, 0, power);
}

void swingTurn(int direction, int power) {
	// direction: 0 for left, 1 for right;
	direction = direction == 0 ? -1 : 1;
	setMovement(power, 0, direction * power)
}

void moveDiagonal(int vector, int power) {
	// vector is 0 to 3, with 0 being straight forward, and 3 being back/left
	// use negative power to move in any of the other four directions
	
	//consider using pothagorean theorem to make sure overall speed is equal in all directions with a constant power
	int drive = 1; 
	int strafe = 1;
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