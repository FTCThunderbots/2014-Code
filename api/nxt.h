// nxt.h
// Header file for nxt.c

#define NXT_INCLUDEGAURD

#ifndef JOYSTICKDRIVER_INCLUDEGAURD
#include "JoystickDriver.c"
#define JOYSTICKDRIVER_INCLUDEGAURD
#endif

void waitStartAPI();
int setAutoDelay();
task trackMatchStart();