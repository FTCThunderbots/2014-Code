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
   
   //don't add the correctJoystick here. If necessary, add it to setMovementFromJoystick()

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

	for(int i = 0; i < 4; i++) {
		power[i] *= MOVE_POWER_SCALE;
      
      
   //nxtDisplayCenteredTextLine(i+2, "%d", power[i]);}

   // please leave the motor names how they are
   // update other files to reflect these names
	motor[leftmotor_1] = power[0];
	motor[rightmotor_1] = power[1];
	#ifndef setting_twoMotors
	motor[leftmotor_2] = power[2];
	motor[rightmotor_2] = power[3];
	#endif
}

void setMovementFromJoystick(byte forward, byte right, byte clockwise) {
	// Scale from the range of the joystick to the range of the motors
	forward = correctJoystick(forward);
	right = correctJoystick(right);
	clockwise = correctJoystick(clockwise);

   // the rest of the code is in setMovement()
   setMovement(forward, right, clockwise);
}

void setMovement(byte forward, byte clockwise) {
	if (abs(power) < 10) power = 0;
	if (abs(turn) < 10) turn = 0;
	//turn = turn * 1.5;
	int leftBrake = 1;
	int rightBrake = 1;
	if (joy1Btn(7)){
		leftBrake = 0;
		//turn = 0;
	}
	if (joy1Btn(8)){
		rightBrake = 0;
		//turn = 0;
	}
	float leftFinal = (float) leftBrake * (power + turn);
	float rightFinal = (float) rightBrake * (-power + turn);

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
	motor[leftmotor_1] = leftFinal;
	motor[rightmotor_1] = rightFinal;
	motor[leftmotor_2] = leftFinal;
	motor[rightmotor_2] = rightFinal;
}

void setMovementFromJoystick(byte forward, byte clockwise) {
   setMovement(correctJoystick(forward), correctJoystick(clockwise));
}

byte correctJoystick(byte joyval) {
	return scaleTo(truncateInt(joyval), &joyRange[0], &motorRange[0]);
}

void scaleByteInputs(byte* x, byte* y) {
	if (abs(*x) > 100)
	{
		*y *= (100.0 / (float)abs(*x));
		*x *= (100.0 / (float)abs(*x));
	}
	if (abs(*y) > 100)
	{
		*x *= (100.0 / (float)abs(*y));
		*y *= (100.0 / (float)abs(*y));
	}
}

void scaleInputs(int* x, int* y) {
	if (abs(*x) > 100)
	{
		*y *= (100.0 / (float)abs(*x));
		*x *= (100.0 / (float)abs(*x));
	}
	if (abs(*y) > 100)
	{
		*x *= (100.0 / (float)abs(*y));
		*y *= (100.0 / (float)abs(*y));
	}
}
