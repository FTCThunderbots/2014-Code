// movement.h
// Header file for movement.c

#define MOVEMENT_INCLUDEGUARD

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

void setMovement(byte forward, byte clockwise);

//byte correctJoystickExp(int joyval);
byte correctJoystickComposite(int joyval);
byte correctJoystick(int joyval);

void setMovementFromJoystick_old(int power, int turn);
float correctJoystick_old(int input);
