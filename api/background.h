// background.h
// Header file for background.c

#define BACKGROUND_INCLUDEGAURD

#ifndef DEBUG_INCLUDEGUARD
#include "debug.c"
#endif

#ifndef MOVEMENT_INCLUDEGAURD
#include "movement.c"
#endif

#ifndef TIMER_INCLUDEGAURD
#include "timer.c"
#endif

void initializeAPI();
task background();
