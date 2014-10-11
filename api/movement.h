// movement.h
// Header file for movement.c

#include "api.h"

void setMovement(byte forward, byte right, byte clockwise);
static byte scaleTo(byte value, ubyte range[3], ubyte scale[3]);