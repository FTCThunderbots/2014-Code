#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,        tmotorTetrix, openLoop)
#pragma config(Motor,	 mtr_S1_C1_2,			backLeft,					tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,			frontRight,				tmotorTetrix,	openLoop)
#pragma config(Motor,	 mtr_S1_C2_2,			backRight,				tmotorTetrix,	openLoop)

#include "2014-Code/api/api.h"

const int JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 128; //should only be changed if a different joystick is used

// Movement
const byte DRIVE_MIN_POWER = 0; //power cannot be in the open interval (0, min)
const byte DRIVE_MAX_POWER = 100; //power cannot exceed max
const byte STRAFE_MIN_POWER = 0;
const byte STRAFE_MAX_POWER = 100;
const byte TURN_MIN_POWER = 0;
const byte TURN_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits

// Motor Constants
const byte MOTOR_MIN_POWER = 0; //not yet implemented
const byte MOTOR_MAX_POWER = 100;

void setMovement(byte forward, byte right, byte clockwise);
void setMovement(byte forward, byte clockwise);
static byte scaleTo(byte value, byte range[3], byte scale[3]);


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

	float power[4] = {frontLeft, frontRight, backLeft, backRight};

	// find max of all wheel powers
	byte max = absmax(power);

	// scale all wheels to fit within motor_max
	if (max > MOTOR_MAX_POWER) {
		float scale = (float)max / MOTOR_MAX_POWER;
		for (int i = 0; i < 4; i++)
			power[i] /= scale;
	}

	for(int i = 0; i < 4; i++)
		power[i] *= MOVE_POWER_SCALE;

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

task main()
{
	setMovement(0, 0);
	waitForStart();
	setMovement(MOTOR_MAX_POWER, 0, 0)
	wait10Msec(750);
}
