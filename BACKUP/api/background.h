// background.h
// Header file for background.c

#define BACKGROUND_INCLUDEGAURD

#ifndef MOVEMENT_INCLUDEGAURD
#include "movement.c"
#endif

#ifndef TIMER_INCLUDEGAURD
#include "timer.c"
#endif

void initializeAPI();
task background();
