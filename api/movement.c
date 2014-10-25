// movement.h
// Contains all code related to the positional movement of the robot
// Lifting code and other functional systems should be defined somewhere else
// Wrappers such as drive, strafe, and rotate should be placed in simplemovement.c

#include "movement.h"

static const byte joyRange[3] = {JOYSTICK_MIN_VALUE, JOYSTICK_MAX_VALUE, JOYSTICK_MAX_VALUE - JOYSTICK_MIN_VALUE};
static const byte driveRange[3] = {DRIVE_MIN_POWER, DRIVE_MAX_POWER, DRIVE_MAX_POWER - DRIVE_MIN_POWER};
static const byte strafeRange[3] = {STRAFE_MIN_POWER, STRAFE_MAX_POWER, STRAFE_MAX_POWER - STRAFE_MIN_POWER};
static const byte turnRange[3] = {TURN_MIN_POWER, TURN_MIN_POWER, TURN_MAX_POWER - TURN_MIN_POWER};
static const byte motorRange[3] = {MOTOR_MIN_POWER, MOTOR_MAX_POWER, MOTOR_MAX_POWER - MOTOR_MIN_POWER};

void setMovement(byte forward, byte right, byte clockwise) {
   // In RobotC, make these arrays static/global and maybe const
	byte joyRange[3] = {JOYSTICK_MIN_VALUE, JOYSTICK_MAX_VALUE, JOYSTICK_MAX_VALUE - JOYSTICK_MIN_VALUE};
	byte driveRange[3] = {DRIVE_MIN_POWER, DRIVE_MAX_POWER, DRIVE_MAX_POWER - DRIVE_MIN_POWER};
	byte strafeRange[3] = {STRAFE_MIN_POWER, STRAFE_MAX_POWER, STRAFE_MAX_POWER - STRAFE_MIN_POWER};
	byte turnRange[3] = {TURN_MIN_POWER, TURN_MIN_POWER, TURN_MAX_POWER - TURN_MIN_POWER};
	// Array format: min, max, difference

	// First, scale all vectors using values found in settings.c
	forward = scaleTo(forward, &joyRange[0], &driveRange[0]);
	right = scaleTo(right, &joyRange[0], &strafeRange[0]);
	clockwise = scaleTo(clockwise, &joyRange[0], &turnRange[0]);

	// Next, assign wheel powers using the mecanum algorithm
	float frontLeft = (-forward - right - clockwise);
	float frontRight = (forward - right - clockwise);
	float backLeft = (-forward + right - clockwise);
	float backRight = (forward + right - clockwise);
	//add note about why/how this works in engineering notebook

	forward = scaleTo(forward, &motorRange[0], &driveRange[0]);
	right = scaleTo(right, &motorRange[0], &strafeRange[0]);
	clockwise = scaleTo(clockwise, &motorRange[0], &turnRange[0]);

	float power[4] = {frontLeft, frontRight, backLeft, backRight};

	// find max of all wheel powers
	byte max = absmax(power, 4);

	// scale all wheels to fit within motor_max
	if (max > MOTOR_MAX_POWER) {
		float scale = (float)max / MOTOR_MAX_POWER;
		for (int i = 0; i < 4; i++)
			power[i] /= scale;
	}

	for(int i = 0; i < 4; i++)
		power[i] *= MOVE_POWER_SCALE;

	motor[Left] = frontLeft;
	motor[Right] = frontRight;
	//motor[bl] = backLeft;
	//motor[br] = backRight;
}

void setMovementFromJoystick(byte forward, byte right, byte clockwise) {
   // In RobotC, make these arrays static/global and maybe const
	// byte joyRange[3] = {JOYSTICK_MIN_VALUE, JOYSTICK_MAX_VALUE, JOYSTICK_MAX_VALUE - JOYSTICK_MIN_VALUE};
	// byte driveRange[3] = {DRIVE_MIN_POWER, DRIVE_MAX_POWER, DRIVE_MAX_POWER - DRIVE_MIN_POWER};
	// byte strafeRange[3] = {STRAFE_MIN_POWER, STRAFE_MAX_POWER, STRAFE_MAX_POWER - STRAFE_MIN_POWER};
	// byte turnRange[3] = {TURN_MIN_POWER, TURN_MIN_POWER, TURN_MAX_POWER - TURN_MIN_POWER};
	// Array format: {min, max, difference}
   

	// Scale all vectors using values found in settings.c
	forward = scaleTo(forward, &joyRange[0], &motorRange[0]);
	right = scaleTo(right, &joyRange[0], &motorRange[0]);
	clockwise = scaleTo(clockwise, &joyRange[0], &motorRange[0]);

   // the rest of the code is in setMovement()
   setMovement(forward, right, clockwise);
}

//for tank drive
void setMovement(byte forward, byte clockwise) {
   setMovement(forward, 0, clockwise);
}

void setMovementFromJoystick(byte forward, byte clockwise) {
	setMovementFromJoystick(forward, 0, clockwise);
}
