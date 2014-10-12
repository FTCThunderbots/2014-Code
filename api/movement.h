// movement.h
// Header file for movement.c

#include "api.h"

void setMovement(byte forward, byte right, byte clockwise);
void setMovement(btye forward, byte clockwise);
static byte scaleTo(byte value, byte range[3], byte scale[3]);