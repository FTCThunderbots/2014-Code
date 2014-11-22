// background.h
// Header file for background.c

#define BACKGROUND_INCLUDEGAURD

#ifndef DEBUG_INCLUDEGAURD
#include "debug.c"
#endif

#ifndef MOVEMENT_INCLUDEGAURD
#include "movement.c"
#endif

#ifndef NXT_INCLUDEGAURD
#include "nxt.c"
#endif

#ifndef TIMER_INCLUDEGAURD
#include "timer.c"
#endif

void initializeRobot();
void initializeAPI();
task background();