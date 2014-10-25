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
	return step(n, 1);
}

// will overload to int if need be
// need to rewrite to use pointers instead of arrays
byte scaleTo(byte value, byte *range, byte *scale) {
	if (abs(value) < *range)
		return 0;
	if (abs(value) > *(range+1))
		return *(scale+1);
	float posInR = (float)(value - *range) / *(range+2); //should be a percent
	return (byte)(*scale) + (posInR * *(range+2));
}

//WHEEL_DIAMETER is in inches and is defined in CONFIGFILE
long inchesToTicks(int inches) {
	return PI*WHEEL_DIAMETER/1440*inches;
}

long inchesToTicks(float inches) {
	return PI*WHEEL_DIAMETER/1440*inches;
}

long inchesToTicks(byte inches) {
	return PI*WHEEL_DIAMETER/1440*inches;
}

byte centimetersToInches(byte centimeters) {
	return centimeters/CM_PER_IN;
}

int centimetersToInches(int centimeters) {
	return centimeters/CM_PER_IN;
}

float centimetersToInches(float centimeters) {
	return centimeters/CM_PER_IN;
}

long centimetersToTicks(byte centimeters) {
	return inchesToTicks(centimetersToInches(centimeters));
}

long centimetersToTicks(int centimeters) {
	return inchesToTicks(centimetersToInches(centimeters));
}

long centimetersToTicks(float centimeters) {
	return inchesToTicks(centimetersToInches(centimeters));
}
