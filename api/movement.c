// movement.h
// Contains all code related to the positional movement of the robot
// Lifting code and other functional systems should be defined somewhere else
// Wrappers such as drive and rotate should be placed in simplemovement.c

#include "movement.h"

// Array format: min, max, difference
static const byte joyRange[3] = {JOYSTICK_MIN_VALUE, JOYSTICK_MAX_VALUE, JOYSTICK_MAX_VALUE - JOYSTICK_MIN_VALUE};
static const byte driveRange[3] = {DRIVE_MIN_POWER, DRIVE_MAX_POWER, DRIVE_MAX_POWER - DRIVE_MIN_POWER};
static const byte strafeRange[3] = {STRAFE_MIN_POWER, STRAFE_MAX_POWER, STRAFE_MAX_POWER - STRAFE_MIN_POWER};
static const byte rotateRange[3] = {ROTATE_MIN_POWER, ROTATE_MIN_POWER, ROTATE_MAX_POWER - ROTATE_MIN_POWER};
static const byte motorRange[3] = {MOTOR_MIN_POWER, MOTOR_MAX_POWER, MOTOR_MAX_POWER - MOTOR_MIN_POWER};

static void setMovement(byte forward, byte right, byte clockwise) {
	// Scale from the range of the motors to the range of the specific movement
	forward = scaleTo(forward, &motorRange[0], &driveRange[0]);
	right = scaleTo(right, &motorRange[0], &strafeRange[0]);
	clockwise = scaleTo(clockwise, &motorRange[0], &rotateRange[0]);

   // multiply each power by its respective weight
	forward *= DRIVE_POWER_WEIGHT;
	right *= STRAFE_POWER_WEIGHT;
	clockwise *= ROTATE_POWER_WEIGHT;

   // Straighten out the robot
	clockwise += TURN_CONSTANT*sgn(forward);

	// Assign wheel powers based on the constituent vectors, then put it all into an array
	float frontLeft = (forward + right + clockwise);
	float frontRight = (-forward + right + clockwise);
	float backLeft = (forward - right + clockwise);
	float backRight = (-forward - right + clockwise);

	float power[4] = {frontLeft, frontRight, backLeft, backRight};

	// Scale all wheels to fit within the max power of a motor, while retaining the power ratios
	byte max = arrAbsmax(power, 4);
	if (max > MOTOR_MAX_POWER) {
		float scale = (float)max / MOTOR_MAX_POWER;
		for (int i = 0; i < 4; i++)
			power[i] /= scale;
	}

	// Multiply all wheel powers by the common movement scale
	for(int i = 0; i < 4; i++)
		power[i] *= MOVE_POWER_SCALE;

  // Finally, set the motor powers
	#ifndef setting_noMotors
	motor[leftmotor_1] = power[0];
	motor[rightmotor_1] = power[1];
	#ifndef setting_twoMotors
	motor[leftmotor_2] = power[2];
	motor[rightmotor_2] = power[3];
	#endif //two motors
	#endif //no motors
}

void setMovement(byte forward, byte clockwise) {
	setMovement(forward, 0, clockwise);
}

// Fixing joystick values

byte correctJoystick(int joyval) {
	return scaleTo(truncateInt(joyval), &joyRange[0], &motorRange[0]);
}

byte correctJoystickExp(int joyval) {
	byte correctVal = abs(correctJoystick(joyval));
	correctVal = (byte)pow(MOTOR_MAX_POWER + 1, (float)correctVal / MOTOR_MAX_POWER);
	correctVal -= 1;
	return sgn(joyval) * correctVal;
}

byte correctJoystickComposite(int joyval) {
	byte linear = correctJoystick(joyval);
	byte expVar = correctJoystickExp(joyval);
	return (expVar + (JOYSTICK_LINEAR_WEIGHT * linear)) / (JOYSTICK_LINEAR_WEIGHT + 1);
}
