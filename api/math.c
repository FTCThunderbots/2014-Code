// math.c
// Contains all math methods and unit conversions

// See header file for methods that need to be implemented
// Please do not add stuff that's included in robotc's default math library

#include "math.h"

// Maximum of range functions

int arrmax(int *a, byte len) {
	int cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = MAX(cummax, *(a+i));
	return cummax;
}

int arrAbsmax(int *a, byte len) {
	int cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = ABSMAX(cummax, *(a+i));
	return cummax;
}

byte arrmax(byte *a, byte len) {
	byte cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = MAX(cummax, *(a+i));
	return cummax;
}

byte arrAbsmax(byte *a, byte len) {
	byte cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = ABSMAX(cummax, *(a+i));
	return cummax;
}

float arrmax(float *a, byte len) {
	float cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = MAX(cummax, *(a+i));
	return cummax;
}

float arrAbsmax(float *a, byte len) {
	float cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = ABSMAX(cummax, *(a+i));
	return cummax;
}

// truncates an int to a byte range without overflowing
byte truncateInt(int n) {
   if (n > 127)
      return 127;
   if (n < -128)
      return -128;
   return (byte)n;
}

// will overload to int if need be
byte scaleTo(byte value, byte *range, byte *scale) {
   byte pol = sgn(value);
	if (abs(value) < *range)
		return 0;
	if (abs(value) > *(range+1))
		return *(scale+1) * pol;
	float posInR = (float)(abs(value) - *range) / *(range+2); //should be a percent
	return pol * ((byte)(*scale) + (posInR * *(scale+2)));
}

// Unit conversion functions

float cmToIn(float cm) {
	return cm /CM_PER_IN;
}

float inToCm(float in) {
	return in * CM_PER_IN;
}

float mToIn(float m) {
	return cmToIn(m * 100) / 100;
}

float inToM(float in) {
	return inToCm(in) / 100;
}

float cmToFt(float cm) {
	return cmToIn(cm) / IN_PER_FT;
}

float mToFt(float m) {
	return mToIn(m) / IN_PER_FT;
}

float ftToCm(float ft) {
	return inToCm(IN_PER_FT*ft);
}

float ftToM(float ft) {
	return inToM(IN_PER_FT*ft);
}

/* Commented until a use is needed
int length(int x) {
   x = abs(x);
   int len = 0;
   while (x > 0) {
      len++;
      x = x/10;
   }
   return len;
}
*/