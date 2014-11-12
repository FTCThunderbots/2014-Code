// math.h
// Header file for math.c

//macros
#define MATH_INCLUDEGAURD
#define IN_PER_FT 12
#define CM_PER_IN 2.54
#define CM_PER_M 100

//Function Macros

#define AVG(a, b) (a+b)/2
#define MAX(a, b) (a >= b ? a : b)
#define ABSMAX(a, b) (MAX(abs(a), abs(b)))

// Maximum value functions

int arrmax(int *a, byte len);
int arrAbsmax(int  *a, byte len);
byte arrmax(byte *a, byte len);
byte arrAbsmax(byte *a, byte len);
float arrmax(float *a, byte len);
float arrAbsmax(float *a, byte len);

//maybe overload to int if need be
static byte scaleTo(byte value, byte *range, byte *scale);

// Unit conversion functions
float inToCm(float in);
float cmToIn(float cm);
float mToIn(float m);
float inToM(float in);
float cmToFt(float cm);
float mToFt(float m);
float ftToCm(float ft);
float ftToM(float ft);