// movement.h
// Header file for movement.c

#define MOVEMENT_INCLUDEGUARD

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

void setMovement(byte forward, byte right, byte clockwise);
void setMovement(byte forward, byte clockwise);
byte correctJoystickExp(int joyval);

void setMovementFromJoystick(int forward, int right, int clockwise);
void setMovementFromJoystick(int forward, int clockwise);
void setMovementFromJoystickExp(int forward, int right, int clockwise);
void setMovementFromJoystickExp(int forward, int clockwise);
void setMovementFromJoystickComposite(int forward, int right, int clockwise);
void setMovementFromJoystickComposite(int forward, int clockwise);

byte correctJoystickExp(int joyval);
byte correctJoystickComposite(int joyval);
byte correctJoystick(int joyval);
void setMovementFromJoystick_old(int power, int turn);
float correctJoystick_old(int input);
