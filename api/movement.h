// movement.h
// Header file for movement.c

#define MOVEMENT_INCLUDEGAURD

#ifndef MATH_INCLUDEGAURD
#include "math.c"
#endif

#ifndef SETTINGS_INCLUDEGAURD
#include "settings.c"
#endif

void setMovement(byte forward, byte right, byte clockwise);
void setMovement(byte forward, byte clockwise);

void setMovementFromJoystick(byte forward, byte right, byte clockwise);
void setMovementFromJoystick(byte forward, byte clockwise);
byte correctJoystick(byte joyval);
void scaleInputs(int* x, int* y);
void scaleByteInputs(byte* x, byte* y);
