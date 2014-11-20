// movement.h
// Contains all code related to the positional movement of the robot
// Lifting code and other functional systems should be defined somewhere else
// Wrappers such as drive, strafe, and rotate should be placed in simplemovement.c

#include "movement.h"

static const byte joyRange[3] = {JOYSTICK_MIN_VALUE, JOYSTICK_MAX_VALUE, JOYSTICK_MAX_VALUE - JOYSTICK_MIN_VALUE};
static const byte driveRange[3] = {DRIVE_MIN_POWER, DRIVE_MAX_POWER, DRIVE_MAX_POWER - DRIVE_MIN_POWER};
static const byte strafeRange[3] = {STRAFE_MIN_POWER, STRAFE_MAX_POWER, STRAFE_MAX_POWER - STRAFE_MIN_POWER};
static const byte rotateRange[3] = {ROTATE_MIN_POWER, ROTATE_MIN_POWER, ROTATE_MAX_POWER - ROTATE_MIN_POWER};
static const byte motorRange[3] = {MOTOR_MIN_POWER, MOTOR_MAX_POWER, MOTOR_MAX_POWER - MOTOR_MIN_POWER};
// Array format: min, max, difference

void setMovement(byte forward, byte right, byte clockwise) {
	// Scale from the range of the motors to the range of the specific movement
	forward = scaleTo(forward, &motorRange[0], &driveRange[0]);
	right = scaleTo(right, &motorRange[0], &strafeRange[0]);
	clockwise = scaleTo(clockwise, &motorRange[0], &rotateRange[0]);
	//nxtDisplayCenteredTextLine(1, "%d", forward);
	forward *= DRIVE_POWER_WEIGHT;
	right *= STRAFE_POWER_WEIGHT;
	clockwise *= ROTATE_POWER_WEIGHT;
	// Next, assign wheel powers using the mecanum
	float frontLeft = (forward + right + clockwise);
	float frontRight = (-forward + right + clockwise);
	float backLeft = (forward - right + clockwise);
	float backRight = (-forward - right + clockwise);
	//add note about why/how this works in engineering notebook
	float power[4] = {frontLeft, frontRight, backLeft, backRight};
	// find max of all wheel powers
	byte max = arrAbsmax(power, 4);
	// scale all wheels to fit within motor_max
	if (max > MOTOR_MAX_POWER) {
		float scale = (float)max / MOTOR_MAX_POWER;
		for (int i = 0; i < 4; i++)
			power[i] /= scale;
	}
	// multiply all by common scale
	for(int i = 0; i < 4; i++)
		power[i] *= MOVE_POWER_SCALE;
	motor[leftmotor_1] = power[0];
	motor[rightmotor_1] = power[1];
	#ifndef setting_twoMotors
	motor[leftmotor_2] = power[2];
	motor[rightmotor_2] = power[3];
	#endif
}

void setMovementFromJoystick(int forward, int right, int clockwise) {
	// Scale from the range of the joystick to the range of the motors
	forward = correctJoystick(forward);
	right = correctJoystick(right);
	clockwise = correctJoystick(clockwise);

   // the rest of the code is in setMovement()
   setMovement(forward, right, clockwise);
}

// Just a shortcut
void setMovement(byte forward, byte clockwise) {
	setMovement(forward, 0, clockwise);
}

// Just a shortcut
void setMovementFromJoystick(int forward, int clockwise) {
   setMovementFromJoystick(forward, 0, clockwise);
}

//deprecated: use setMovementFromJoystick() with the same arguments
void setMovementFromJoystick_old(int power, int turn) {
	power = correctJoystick_old(power);
	turn = correctJoystick_old(turn);
	float leftFinal = (float)(power + turn);
	float rightFinal = (float)(-power + turn);
	if (abs(leftFinal) > 100)
	{
		rightFinal *= 100 / abs(leftFinal);
		leftFinal *= 100 / abs(leftFinal);
	}
	if (abs(rightFinal) > 100)
	{
		leftFinal *= 100 / abs(rightFinal);
		rightFinal *= 100 / abs(rightFinal);
	}
	motor[leftmotor_1] = -leftFinal;
	motor[rightmotor_1] = rightFinal;
	motor[leftmotor_2] = -leftFinal;
	motor[rightmotor_2] = rightFinal;
}

byte correctJoystick(int joyval) {
	return scaleTo(truncateInt(joyval), &joyRange[0], &motorRange[0]);
}

//deprecated: use correctJoystick() with the same arguments
float correctJoystick_old(int input){
	if (abs(input) < JOYSTICK_MIN_VALUE)
		input = 0;
	else
		input -= POLARITY(input) * JOYSTICK_MIN_VALUE;
	return (float)input / 1.07;
}
