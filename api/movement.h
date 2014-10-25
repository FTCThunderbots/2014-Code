// movement.h
// Header file for movement.c

#include "api.c"
#include "math.c"
#include "settings.c"

void setMovement(byte forward, byte right, byte clockwise);
void setMovement(byte forward, byte clockwise);

void setMovementFromJoystick(byte forward, byte right, byte clockwise);
void setMovementFromJoystick(byte forward, byte clockwise);
