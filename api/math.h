/* math.h | Header file for math.c
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

#define MATH_INCLUDEGUARD

// Unit conversion constants
#define IN_PER_FT 12
#define CM_PER_IN 2.54
#define CM_PER_M 100

//Function Macros

#define AVG(a, b) (a+b)/2
#define MAX(a, b) (a >= b ? a : b)
#define ABSMAX(a, b) (MAX(abs(a), abs(b)))

// Misc functions

float arrAbsmax(float *a, byte len);
byte truncateInt(int n);
byte scaleTo(byte value, byte *range, byte *scale);

// Unit conversions

float cmToIn(float cm);
float inToCm(float in);
float mToIn(float m);
float inToM(float in);
float cmToFt(float cm);
float mToFt(float m);
float ftToCm(float ft);
float ftToM(float ft);
