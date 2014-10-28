// math.h
// Header file for math.c

//macros
#define MATH_INCLUDEGAURD
#define IN_PER_FT 12
#define FT_PER_IN 1/IN_PER_FT
#define CM_PER_IN 2.54
#define IN_PER_CM 1/CM_PER_IN
#define CM_PER_M 100
#define M_PER_CM 1/CM_PER_M
#define IN_PER_M IN_PER_CM*CM_PER_M
#define M_PER_IN 1/IN_PER_M

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
float mToIn(float m);
float inToM(float in);
float cmToFt(float cm);
float mToFt(float m);
float ftToCm(float ft);
float ftToM(float ft);

//conversion to ticks
long inToTicks(int inches);
long inToTicks(float inches);
long inToTicks(byte inches);
long cmToTicks(byte centimeters);
long cmToTicks(int centimeters);
long cmToTicks(float centimeters);
long mToTicks(float meters);
long mToTicks(byte meters);
long mToTicks(int meters);
long ftToTicks(int feet);
long ftToTicks(byte feet);
long ftToTicks(float feet);
