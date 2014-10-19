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

int max(int a[]) {
	int max = a[0];
	for (int i = 1; i < a.length; i++)
		max = max(max, a[i]);
	return max;
}

int absmax(int a[]) {
	int max = a[0];
	for (int i = 1; i < a.length; i++)
		max = absmax(max, a[i]);
	return max;
}

byte max(byte a, byte b) {
	return a >= b ? a : b;
}

byte absmax(int a, int b) {
	return max(abs(a), abs(b));
}

byte max(byte a[]) {
	byte max = a[0];
	for (int i = 1; i < a.length; i++)
		max = max(max, a[i]);
	return max;
}

byte absmax(byte a[]) {
	byte max = a[0];
	for (int i = 1; i < a.length; i++)
		max = absmax(max, a[i]);
	return max;
}

float max(float a, float b) {
	//CAUTION: may have minor imprecisions between two very close numbers
	return a >= b ? a : b;
}

float absmax(float a, float b) {
	return max(abs(a), abs(b));
}

float max(float a[]) {
	float max = a[0];
	for (int i = 1; i < a.length; i++)
		max = max(max, a[i]);
	return max;
}

float absmax(float a[]) {
	float max = a[0];
	for (int i = 1; i < a.length; i++)
		max = absmax(max, a[i]);
	return max;
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
static byte scaleTo(byte value, byte range[3], byte scale[3]) {
	if (abs(value) < range[0])
		return 0;
	if (abs(value) > range[1])
		return scale[1];
	float posInR = (float)(value - range[0]) / (range[2]); //should be a percent
	return (byte)scale[0] + (posInR * range[2]);
}