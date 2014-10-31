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

int max(int *a, byte len) {
	int cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(cummax, *(a+i));
	return cummax;
}

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

byte max(byte *a, byte len) {
	byte cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(cummax, *(a+i));
	return cummax;
}

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

float max(float *a, byte len) {
	float cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(cummax, *(a+i));
	return cummax;
}

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
	return step(n, 1.0);
}

// will overload to int if need be
byte scaleTo(byte value, byte *range, byte *scale) {
	if (abs(value) < *range)
		return 0;
	if (abs(value) > *(range+1))
		return *(scale+1);
	float posInR = (float)(value - *range) / *(range+2); //should be a percent
	return (byte)(*scale) + (posInR * *(range+2));
}

// Unit conversion functions

float cmToIn(float cm) {
	return cm * (1/CM_PER_IN);
}

float inToCm(float in) {
	return in * CM_PER_IN;
}

float mToIn(float m) {
	return cmToIn((1/((1/CM_PER_IN)*CM_PER_M))*m);
}

float inToM(float in) {
	return in * (1/((1/CM_PER_IN)*CM_PER_M));
}

float cmToFt(float cm) {
	return (1/IN_PER_FT)*cmToIn(cm);
}

float mToFt(float m) {
	return (1/IN_PER_FT)*mToIn(m);
}

float ftToCm(float ft) {
	return inToCm(IN_PER_FT*ft);
}

float ftToM(float ft) {
	return inToM(IN_PER_FT*ft);
}

/*long inToTicks(int inches) {
	return ((PI*WHEEL_DIAMETER))/ENCODER_TICKS_PER_INCH)*inches;
}

long inToTicks(float inches) {
	return PI*WHEEL_DIAMETER/ENCODER_TICKS_PER_INCH*inches;
}

long inToTicks(byte inches) {
	return PI*WHEEL_DIAMETER/ENCODER_TICKS_PER_INCH*inches;
}

long cmToTicks(byte centimeters) {
	return inchesToTicks(cmToIn((float)centimeters));
}

long cmToTicks(int centimeters) {
	return inchesToTicks(cmToIn((float)centimeters));
}

long cmToTicks(float centimeters) {
	return inchesToTicks(cmToIn(centimeters));
}

long mToTicks(float meters) {
	return inchesToTicks(mToIn(meters));
}

long mToTicks(byte meters) {
	return inchesToTicks(mToIn((float)meters));
}

long mToTicks(int meters) {
	return inchesToTicks(mToIn((float)meters));
}

long ftToTicks(int feet) {
	return inchesToTicks(ftToIn((float)feet));
}

long ftToTicks(byte feet) {
	return inchesToTicks(ftToIn((float)feet));
}

long ftToTicks(float feet) {
	return inchesToTicks(ftToIn(feet));
}*/

/* float degreesToRadians(const float fDegrees); and
 * short radiansToDegrees(const float fRadians);
 * are predefined by the ROBOTC mathe library,
 * which is included by default.
 */
