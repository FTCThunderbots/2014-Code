// movement.h
// should contain all code related to the positional movement of the robot
// lifting code and other functional systems should be defined somewhere else

#include <math.h>
#include "config.h"
#include "settings.h"
#include "movement.h"

//void setMovement(short forward, short right, short clockwise)
void setMovement(byte forward, byte right, byte clockwise) {
   // In RobotC, make these arrays static/global
   // Try to declare these as const with a functioning compiler
	ubyte JOYRANGE[3] = {JOYSTICK_MIN_VALUE, JOYSTICK_MAX_VALUE, JOYSTICK_MAX_VALUE - JOYSTICK_MIN_VALUE};
	ubyte DRVRANGE[3] = {DRIVE_MIN_POWER, DRIVE_MAX_POWER, DRIVE_MAX_POWER - DRIVE_MIN_POWER};
	ubyte STFRANGE[3] = {STRAFE_MIN_POWER, STRAFE_MAX_POWER, STRAFE_MAX_POWER - STRAFE_MIN_POWER};
	ubyte TRNRANGE[3] = {TURN_MIN_POWER, TURN_MIN_POWER, TURN_MAX_POWER - TURN_MIN_POWER};
	// Array format: min, max, difference

	// First, scale all vectors using values found in settings.h
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
	byte maxLeft = abs(frontLeft)>=abs(backLeft)) : abs(frontLeft) ? abs(backLeft);
	byte maxRight = abs(frontRight)>=abs(backRight) : abs(frontRight) ? abs(backRight);
	byte max = maxLeft>=maxRight : maxLeft ? maxRight;
	
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
//static short scaleTo(short value, short range[3], short scale[3])
static byte scaleTo(byte value, ubyte range[3], ubyte scale[3]) {
	if (abs(value) < range[0])
		return 0;
	if (abs(value) > range[1])
		return scale[1];
	float posInR = value / (range[2]);
	return (byte)range[0] + (posInR * range[2]);
}