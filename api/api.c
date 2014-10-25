// api.h
// Contiains imports for all api files

//#ifndef API_INCLUDEGUARD
//#define API_INCLUDEGUARD
// files will only be included once, preventing infinite recursion
#ifndef WHEEL_DIAMETER
#warn "WHEEL_DIAMETER is not defined in CONFIGFILE"
#warn "ALL PRECISE MOVEMENT FUNCTIONS WILL NOT WORK!!!!!"
#endif

#ifdef CONFIGFILE
#include CONFIGFILE
#else
#include "../config/default_config.c"
#endif
//if user has defined a custom config file, include it
//else, include default config

// Please keep this list alphabetized
// background.c
// Contains code for a background processes task

#include "timer.c"
//#include "movement.c" //uncomment this line if it's giving compile errors for setMovement()
//-------------------------------------------------------------------
void initializeAPI() {
	setMovement(0,0,0);
	timeInit();
}

task background() {
	monitorSysTimer();
	updateAllTimers();
}
//-------------------------------------------------------------------
// functions.c
// Contains all functions pertaining to non-movement functions of the robot
// Ex. Lifts, servos

#include "functions.h"
//-------------------------------------------------------------------

// math.c
// Contains all math methods and unit conversions

// See header file for methods that need to be implemented
// Please do not add stuff that's included in robotc's default math library

#include "math.h"

// Maximum of range functions

int max(int a, int b) {
	return a >= b ? a : b;
}

int absmax(int a, int b) {
	return max(abs(a), abs(b));
}

// robotc cannot accept arrays as args: rewrite
int max(int *a, byte len) {
	int cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(cummax, *(a+i));
	return cummax;
}

// robotc cannot accept arrays as args: rewrite
int absmax(int *a, byte len) {
	int cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = absmax(cummax, *(a+i));
	return cummax;
}

byte max(byte a, byte b) {
	return a >= b ? a : b;
}

byte absmax(byte a, byte b) {
	return max(abs(a), abs(b));
}

// robotc cannot accept arrays as args: rewrite
byte max(byte *a, byte len) {
	byte cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(cummax, *(a+i));
	return cummax;
}

// robotc cannot accept arrays as args: rewrite
byte absmax(byte *a, byte len) {
	byte cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = absmax(cummax, *(a+i));
	return cummax;
}

float max(float a, float b) {
	//CAUTION: may have minor imprecisions between two very close numbers
	return a >= b ? a : b;
}

float absmax(float a, float b) {
	return max(abs(a), abs(b));
}

// robotc cannot accept arrays as args: rewrite
float max(float *a, byte len) {
	float cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(cummax, *(a+i));
	return cummax;
}

// robotc cannot accept arrays as args: rewrite
float absmax(float *a, byte len) {
	float cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = absmax(cummax, *(a+i));
	return cummax;
}

// Integer-step functions

int step(int n, int multiple) {
	int factor = n / multiple;
	return n - (factor * multiple);
}

byte step(byte n, byte multiple) {
	byte factor = n / multiple;
	return n - (factor * multiple);
}

float step(float n, float multiple) {
	byte factor = n / multiple;
	return n - (factor * multiple);
}

float step(float n) {
	return step(n, 1);
}

// will overload to int if need be
// need to rewrite to use pointers instead of arrays
static byte scaleTo(byte value, byte *range, byte *scale) {
	if (abs(value) < *range)
		return 0;
	if (abs(value) > *(range+1))
		return *(scale+1);
	float posInR = (float)(value - *range) / *(range+2); //should be a percent
	return (byte)(*scale) + (posInR * *(range+2));
}
//----------------------------------------------------------------------------
// movement.c
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
	forward = scaleTo(forward, &JOYRANGE[0], &DRVRANGE[0]);
	right = scaleTo(right, &JOYRANGE[0], &STFRANGE[0]);
	clockwise = scaleTo(clockwise, &JOYRANGE[0], &TRNRANGE[0]);

	// Next, assign wheel powers using the mecanum algorithm
	float frontLeft = (-forward - right - clockwise)/3;
	float frontRight = (forward - right - clockwise)/3;
	float backLeft = (-forward + right - clockwise)/3;
	float backRight = (forward + right - clockwise)/3;
	//add note about why/how this works in engineering notebook

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

	//motor[fl] = frontLeft;
	//motor[fr] = frontRight;
	//motor[bl] = backLeft;
	//motor[br] = backRight;
}

//for tank drive
void setMovement(byte forward, byte clockwise) {
	setMovement(forward, 0, clockwise);
}
//----------------------------------------------------------------
// ruler.c
// A custom encoder measurement system
// Should be very useful
//--------------------------------------------------------------------
// sensors.c
// Contains methods for getting the values of sensors on the robot

#include "sensors.h"
//----------------------------------------------------------------------------
// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments


// Joysticks
const int JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 127; //should only be changed if a different joystick is used

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

//Todo: wheel diameter and tick counts
//-------------------------------------------------------------------------------------
// simplemovement.c
// Contains very basic movement functions
// All functions are wrappers of functions in movement

#include "simplemovement.h"

//look in header for functions that need implementations

void drive(byte power) {
	setMovement(power, 0, 0);
}

void strafe(byte power) {
	setMovement(0, power, 0);
}

void rotate(byte power) {
	setMovement(0, 0, power);
}

void halt() {
	setMovement(0,0,0);
}

void swingTurn(byte direction, byte power) {
	// direction: 0 for left, 1 for right;
	direction = direction == 0 ? -1 : 1;
	setMovement(power, 0, direction * power);
}

void moveDiagonal(byte vector, byte power) {
	// vector is 0 to 3, with 0 being straight forward, and 3 being back/left
	// use negative power to move in any of the other four directions

	//consider using pothagorean theorem to make sure overall speed is equal in all directions with a constant power
	byte drive = 1;
	byte strafe = 1;
	if (power < 0)
		strafe = -1;
	if (vector == 0)
		strafe = 0;
	if (vector == 2)
		drive = 0;
	if (vector == 3)
		drive = -1;

	setMovement(power * drive, power * strafe, 0);
}

// should move to math.c
// or even better...
// TODO: create step function in math
int correctDegs(int degs) {
	int fullspins = degs/360;
	return degs-(360*fullspins)
}

void rotateDeg(int degs, byte power){
	#warn "Compass sensor is used in rotateDeg"
	//uses compass sensor
	int startFacing = SensorValue[compass];
	setMovement(0, 0, power);
	while(SensorValue[compass] != correctDegs(startFacing+degs)){}
	halt();
}

void rotateRad(int rads, byte power) {
	rotateDeg(radiansToDegrees(rads), power);
}

void rotateTicks(long ticks, byte power) {
#warn "rotateTicks is not implemented"
}

//----------------------------------------------------------------------------
// timer.c
// A custom timing system

#include "timer.h"

#ifdef timersused
static Timer_t *timerSet[timersused];
#else
static Timer_t *timerSet[0];
#endif

static long currentTime = 0;
static byte minutesPassed = 0;
static int extraMS = 0;
static byte timers = 0;

int initTimer(pTimer_t timer) {
	if (timer->initialized)
		return -1;
	clearTimer(timer);
	timer->running = false;
	timer->start = 0;
	timer->initialized = true;
	timerSet[timers++] = *timer;
	// The right side should not be dereferenced, but robotC complains otherwise
	// timerSet is an array of pointers, not objects...?,
	return 0;
}

void startTimer(pTimer_t timer) {
	timer->previousTime = timer->milliseconds;
	timer->running = true;
	timer->start = timeInMS();
}

void stopTimer(Timer_t *timer) {
	timer->running = false;
}

void clearTimer(pTimer_t timer) {
	timer->previousTime = 0;
	timer->seconds = 0;
	timer->deciseconds = 0;
	timer->centiseconds = 0;
	timer->milliseconds = 0;
}

void updateTimer(pTimer_t timer) {
	if (timer->running) {
		long milliseconds = timer->previousTime + (timeInMS() - timer->start);
		timer->milliseconds = milliseconds;
		timer->seconds = (int)(milliseconds / 1000);
		timer->deciseconds = (int)(milliseconds / 100);
		timer->centiseconds = milliseconds / 10;
	}
}

void updateAllTimers() {
	for (int i = 0; i < timers; i++)
		updateTimer(&timerSet[i]);
		// I don't think the address operator should be required here,
		// but RobotC complains if it's absent
}

void monitorSysTimer() {
	currentTime = time1[T1];
	if (currentTime >= 30000) {
		minutesPassed++;
		extraMS += time1[T1] - 30000; //should be zero or negligible, but it's here just in case
		ClearTimer(T1);
		currentTime = time1[T1];
	}
}

void timeInit() {
	ClearTimer(T1);
}

//total milliseconds of runtime
long timeInMS() {
	return extraMS + currentTime + (minutesPassed * 30000);
}

//total centiseconds of runtime
long timeInCS() {
	return timeInMS() / 10;
}

//total deciseconds of runtime
int timeInDS() {
	return (int)(timeInMS() / 100);
}

//total seconds of runtime
int timeInS() {
	return (int)(timeInMS() / 1000);
}

//seconds of runtime, but in a float
float runtime() {
	return (float) timeInMS() / 1000;
}
//---------------------------------------------------------------------------
// and everyone's favorite...
#include "JoystickDriver.c"

//#endif /* include guard */

task main() {
	//may need to rephrase based on how wide the NXT screen is
	nxtDisplayCenteredTextLine(2, "This is the API");
	nxtDisplayCenteredTextLine(3, "There's no executable code here");
	nxtDisplayCenteredTextLine(5, "Please see documentation");
	nxtDisplayCenteredTextLine(6, "Or ask someone else");
	wait1Msec(20000);
}
