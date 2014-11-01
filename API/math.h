// math.h
// Header file for math.c

//macros
#define MATH_INCLUDEGAURD
#define IN_PER_FT 12
#define CM_PER_IN 2.54
#define CM_PER_M 100

//Function Macros

#define MAX(a, b) ((a>=b) ? a : b)
#define ABS_MAX(a, b) (MAX(abs(a), abs(b)))

// Maximum value functions

//int max(int a, int b);
//int absmax(int a, int b);
int max(int *a, byte len);
int absmax(int  *a, byte len);

//byte max(byte a, byte b);
//byte absmax(byte a, byte b);
byte max(byte *a, byte len);
byte absmax(byte *a, byte len);

//float max(float a, float b);
//float absmax(float a, float b);
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
float mToIn(float m);
float inToM(float in);
float cmToFt(float cm);
float mToFt(float m);
float ftToCm(float ft);
float ftToM(float ft);