// movement.h
// Contains all code related to the positional movement of the robot
// Lifting code and other functional systems should be defined somewhere else
// Wrappers such as drive, strafe, and rotate should be placed in simplemovement.c

#include "movement.h"

void setMovement(byte forward, byte right, byte clockwise) {
   // In RobotC, make these arrays static/global and maybe const
	byte JOYRANGE[3] = {JOYSTICK_MIN_VALUE, JOYSTICK_MAX_VALUE, JOYSTICK_MAX_VALUE - JOYSTICK_MIN_VALUE};
	byte DRVRANGE[3] = {DRIVE_MIN_POWER, DRIVE_MAX_POWER, DRIVE_MAX_POWER - DRIVE_MIN_POWER};
	byte STFRANGE[3] = {STRAFE_MIN_POWER, STRAFE_MAX_POWER, STRAFE_MAX_POWER - STRAFE_MIN_POWER};
	byte TRNRANGE[3] = {TURN_MIN_POWER, TURN_MIN_POWER, TURN_MAX_POWER - TURN_MIN_POWER};
	// Array format: min, max, difference

	// First, scale all vectors using values found in settings.c
	forward = scaleTo(forward, JOYRANGE, DRVRANGE);
	right = scaleTo(right, JOYRANGE, STFRANGE);
	clockwise = scaleTo(clockwise, JOYRANGE, TRNRANGE);	
	
	// Next, assign wheel powers using the mecanum algorithm
	float frontLeft = (-forward - right - clockwise)/3;
	float frontRight = (forward - right - clockwise)/3;
	float backLeft = (-forward + right - clockwise)/3;
	float backRight = (forward + right - clockwise)/3;
	//add note about why/how this works in engineering notebook
	
	// find max of all wheel powers
	byte max = absmax({frontLeft, frontRight, backLeft, backRight});
	
	// scale all wheels to fit within motor_max
	if (max > MOTOR_MAX_POWER) {
		float scale = (float)max / MOTOR_MAX_POWER;
		frontLeft /= scale;
		frontRight /= scale;
		backLeft /= scale;
		backRight /= scale;
	}
	//motor[fl] = frontLeft;
	//motor[fr] = frontRight;
	//motor[bl] = backLeft;
	//motor[br] = backRight;
}

//for tank drive
void setMovement(byte forward, byte clockwise) {
	setMovement(forward, 0, clockwise);
}

static byte scaleTo(byte value, byte range[3], byte scale[3]) {
	if (abs(value) < range[0])
		return 0;
	if (abs(value) > range[1])
		return scale[1];
	float posInR = (float)(value - range[0]) / (range[2]); //should be a percent
	return (byte)scale[0] + (posInR * range[2]);
}