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

void setMovementFromJoystick(int forward, int right, int clockwise);
void setMovementFromJoystick(int forward, int clockwise);
byte correctJoystick(int joyval);
void setMovementFromJoystick_old(int power, int turn);
float correctJoystick_old(int input);
