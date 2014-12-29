// math.h
// Header file for math.c

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
