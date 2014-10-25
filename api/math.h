// math.h
// Header file for math.c

#include "api.c"

//macros
#define CM_PER_IN 2.540000
#define IN_PER_CM 1/CM_PER_IN
#define IN_PER_FT 12
#define FT_PER_IN 1/IN_PER_FT
#define CM_PER_FT CM_PER_IN*IN_PER_FT
#define FT_PER_CM 1/CM_PER_FT
#define CM_PER_MT 100
#define MT_PER_CM 1/CM_PER_MT
#define IN_PER_MT IN_PER_CM*CM_PER_IN
#define MT_PER_IN 1/IN_PER_MT


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

// Not yet implemented:
long inchesToTicks(byte inches);
long inchesToTicks(int inches);
long inchesToTicks(float inches);
long centimetersToTicks(byte centimeters);
long centimetersToTicks(int centimeters);
long centimetersToTicks(float centimeters);
byte centimetersToInches(byte centimeters);
int centimetersToInches(int centimeters);
float centimetersToInches(float centimeters);
// Tick conversions need to use data from settings.c
//int degreesToTurnTicks(int degrees);
//int degreesToSwingTicks(int degrees);
//int radiansToTurnTicks(int radians); //copy with float
//int radiansToSwingTicks(int radians); //copy with float
