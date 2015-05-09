/* math.c | Common math functions and unit conversions
 * Copyright (C) 2015 Thunderbots-5604
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

// See header file for methods that need to be implemented
// Please do not add stuff that's included in robotc's default math library

#include "math.h"

// Maximum of range functions

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
	return cm / CM_PER_IN;
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
