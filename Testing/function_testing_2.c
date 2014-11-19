#include "stdio.h"

int motor[4];
int leftmotor_1 = 0;
int rightmotor_1 = 1;
int leftmotor_2 = 2;
int rightmotor_2 = 0;

typedef char byte;

// header file

const int JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 127; //should only be changed if a different joystick is used

// Movement
const byte DRIVE_MIN_POWER = 0; //abs(power) cannot be in the open interval (0, min)
const byte DRIVE_MAX_POWER = 100; //abs(power) cannot exceed max
const byte STRAFE_MIN_POWER = 0;
const byte STRAFE_MAX_POWER = 100;
const byte ROTATE_MIN_POWER = 0;
const byte ROTATE_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits
const float DRIVE_POWER_WEIGHT = 1.0; //weights are used for changing responsiveness of different movements
const float STRAFE_POWER_WEIGHT = 1.0;
const float ROTATE_POWER_WEIGHT = 1.0;

// Motor Constants
const byte MOTOR_MIN_POWER = 0; //not yet implemented
const byte MOTOR_MAX_POWER = 100;

#define MAX(a, b) (a >= b ? a : b)
#define ABSMAX(a, b) (MAX(abs(a), abs(b)))
#define POLARITY(n) n!=0?abs(n)/n:1 

void setMovement(byte forward, byte right, byte clockwise);

void setMovementFromJoystick(byte forward, byte right, byte clockwise);
byte correctJoystick(byte joyval);
void scaleInputs(int* x, int* y);
void scaleByteInputs(byte* x, byte* y);

// main file

static byte joyRange[3] = {10, 127, 117};
static byte driveRange[3] = {0, 100, 100};
static byte strafeRange[3] = {0, 100, 100};
static byte rotateRange[3] = {0, 100, 100};
static byte motorRange[3] = {0, 100, 100};
// Array format: min, max, difference

byte scaleTo(byte value, byte *range, byte *scale) {
   byte pol = POLARITY(value);
	if (abs(value) < *range)
		return 0;
	if (abs(value) > *(range+1))
		return *(scale+1) * pol;
	float posInR = (float)(abs(value) - *range) / *(range+2); //should be a percent
	return pol * (byte)(*scale) + (posInR * *(scale+2));
}

float arrAbsmax(float *a, byte len) {
	float cummax = *a;
	int i;
	for (i = 1; i < len; i++)
		cummax = ABSMAX(cummax, *(a+i));
	return cummax;
}

void setMovement(byte forward, byte right, byte clockwise) {
		// Scale from the range of the motors to the range of the specific movement
	forward = scaleTo(forward, &motorRange[0], &driveRange[0]);
	right = scaleTo(right, &motorRange[0], &strafeRange[0]);
	clockwise = scaleTo(clockwise, &motorRange[0], &rotateRange[0]);
	//scaleByteInputs(&forward, &clockwise);

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
		int i;
		for (i = 0; i < 4; i++)
			power[i] /= scale;
	}

	int i;
	for(i = 0; i < 4; i++)
		power[i] *= MOVE_POWER_SCALE;

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

byte correctJoystick(byte joyval) {
	return scaleTo(joyval, &joyRange[0], &motorRange[0]);
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

#define op_Polarity

int main() {	
	#ifdef op_scaleTo
	byte samples[] = {0,10, 50, 68, 100, 127, 150};
	int i;
	for (i = 0; i < 7; i++) {
		printf("%d scales to %d\n", (int)samples[i], (int)scaleTo(samples[i], &joyRange[0], &motorRange[0]));
	}
	#endif
	#ifdef op_Polarity
	byte samples[] = {8, -2, -120, 0, 1, -23, 128, -1};
	byte pols[8];
	int i;
	for (i = 0; i < 8; i++) {
		pols[i] = POLARITY(samples[i]);
	}
	for (i = 0; i < 8; i++) {
		printf("%d ", (int)pols[i]);
	}
	return 0;
	#endif
}