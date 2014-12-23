// movement.h
// Header file for movement.c

#define MOVEMENT_INCLUDEGUARD

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

static void setMovement(byte forward, byte right, byte clockwise);
void setMovement(byte forward, byte clockwise);

byte correctJoystickComposite(int joyval);
byte correctJoystickExp(int joyval);
byte correctJoystick(int joyval);