// math.h
// Header file for math.c

#define MATH_INCLUDEGAURD

// Maximum value functions

int max(int a, int b);
int absmax(int a, int b);
int max(int *a, byte len);
int absmax(int  *a, byte len);

byte max(byte a, byte b);
byte absmax(byte a, byte b);
byte max(byte *a, byte len);
byte absmax(byte *a, byte len);

float max(float a, float b);
float absmax(float a, float b);
float max(float *a, byte len);
float absmax(float *a, byte len);

int step(int n, int multiple);
byte step(byte n, byte multiple);
float step(float n, float multiple);
float step(float n);

//maybe overload to int if need be
static byte scaleTo(byte value, byte *range, byte *scale);

// Unit conversion functions
float inToCm(float in);
float cmToIn(float cm);
float degsToRads(float degs);
float radsToDegs(float rads);