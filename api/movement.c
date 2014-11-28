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

	forward *= DRIVE_POWER_WEIGHT;
	right *= STRAFE_POWER_WEIGHT;
	clockwise *= ROTATE_POWER_WEIGHT;

   // Straighten out the robot
	clockwise += TURN_CONSTANT*sgn(forward);

	// Assign wheel powers based on the constituent vectors
	float frontLeft = (forward + right + clockwise);
	float frontRight = (-forward + right + clockwise);
	float backLeft = (forward - right + clockwise);
	float backRight = (-forward - right + clockwise);

	float power[4] = {frontLeft, frontRight, backLeft, backRight};

	// scale all wheels to fit within the max power of a motor, while retaining the power ratios
	byte max = arrAbsmax(power, 4);
	if (max > MOTOR_MAX_POWER) {
		float scale = (float)max / MOTOR_MAX_POWER;
		for (int i = 0; i < 4; i++)
			power[i] /= scale;
	}
	// multiply all by the common movement scale
	for(int i = 0; i < 4; i++)
		power[i] *= MOVE_POWER_SCALE;

	#ifndef setting_noMotors
	motor[leftmotor_1] = power[0];
	motor[rightmotor_1] = power[1];
	#ifndef setting_twoMotors
	motor[leftmotor_2] = power[2];
	motor[rightmotor_2] = power[3];
	#endif //two motors
	#endif //no motors
}

void setMovementFromJoystick(int forward, int right, int clockwise) {

	// Scale from the range of the joystick to the range of the motors
	forward = correctJoystick(forward);
	right = correctJoystick(right);
	clockwise = correctJoystick(clockwise);

   // the rest of the code is in setMovement()
   setMovement(forward, right, clockwise);
}

void setMovementFromJoystickExp(int forward, int right, int clockwise) {
	forward = correctJoystickExp(forward);
	right = correctJoystickExp(right);
	clockwise = correctJoystickExp(clockwise);

   setMovement(forward, right, clockwise);
}

// shortcut
void setMovement(byte forward, byte clockwise) {
	setMovement(forward, 0, clockwise);
}

// shortcut
void setMovementFromJoystick(int forward, int clockwise) {
   setMovementFromJoystick(forward, 0, clockwise);
}

// shortcut
void setMovementFromJoystickExp(int forward, int clockwise) {
   setMovementFromJoystickExp(forward, 0, clockwise);
}

// Returns a number -100 to +100
byte correctJoystick(int joyval) {
	return scaleTo(truncateInt(joyval), &joyRange[0], &motorRange[0]);
}

int correctJoystickExp(int joyval) {
   int correctVal = abs(correctJoystick(joyval));
   correctVal += JOYSTICK_EXPONENTIAL_SCALE;
   int maxVal = MOTOR_MAX_POWER + JOYSTICK_EXPONENTIAL_SCALE;

   correctVal = pow(MOTOR_MAX_POWER + 1, (float)correctVal / maxVal); //the 1 here is a magic number
   correctVal -= pow(MOTOR_MAX_POWER + 1, JOYSTICK_EXPONENTIAL_SCALE / maxVal);
   return sgn(joyval) * correctVal;
}

float compositeScaleTo(int input) {


float scaleJoyExp(int input) {
  if (abs(input) <= 5) return 0;
	float fInput = (float)abs(input);
	return sgn(input)*(pow(101, fInput/128.0) - 1); //1 represents f(0)
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

//deprecated: use correctJoystick() with the same arguments
float correctJoystick_old(int input){
	if (abs(input) < JOYSTICK_MIN_VALUE)
		input = 0;
	else
		input -= sgn(input) * JOYSTICK_MIN_VALUE;
	return (float)input / 1.07;
}
