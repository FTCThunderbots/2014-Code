// math.h
// Header file for math.c

#include "api.h"

// Maximum value functions

int max(int a, int b);
int absmax(int a, int b);
int max(int a[]);
int absmax(int  a[]);

byte max(byte a, byte b);
byte absmax(byte a, byte b);
byte max(byte a[]);
byte absmax(byte a[]);

float max(float a, float b);
float absmax(float a, float b);
float max(float a[]);
float absmax(float a[]);

int step(int n, int multiple);
byte step(byte n, byte multiple);
float step(float n, float multiple);
float step(float n);

//maybe overload to int if need be
static byte scaleTo(byte value, byte range[3], byte scale[3]);

// Not yet implemented:
int inchesToTicks(int inches);
int inchesToTicks(float inches);
int centimetersToTicks(int centimeters);
int inchesToTicks(float centimeters);
// Tick conversions need to use data from settings.c
int degreesToTurnTicks(int degrees);
int degreesToSwingTicks(int degrees);
int radiansToTurnTicks(int radians); //copy with float
int radiansToSwingTicks(int radians); //copy with float