// Mecanum Drive System code
// Written by Zach Ohara of FTC 5604, Thunderbots
// Algorithm has been verified correct by Jon Bush of team 6559 Geared Reaction

// This file is just a placeholder for the algorithm involved, and should be
// moved to a more permanent movement file

// Rollers should form an 'X' shape when looking down from above the robot
// They can be repositioned later, but the algorithm must be adjusted
// Do NOT reverse any motors in the pragma configurations

// DO NOT INCLUDE THIS FILE. IT IS NOT FUNCTIONAL. IT IS PRETTY AND DEMONSTRATIVE.
// INSTEAD USE movement.c

typedef struct PowerSet {
	short frontLeft;
	short frontRight;
	short backLeft;
	short backRight;
} PowerSet_t;

PowerSet_t powerset(short forward, short right, short clockwise) {
	struct PowerSet finalpowers;
	finalpowers.frontLeft = (-forward - right - clockwise)/3;
	finalpowers.frontRight = (forward - right - clockwise)/3;
	finalpowers.backLeft = (-forward + right - clockwise)/3;
	finalpowers.backRight = (forward + right - clockwise)/3;
	return finalpowers;
	// Remind Zach to add something about why this works to the engineering notebook
}