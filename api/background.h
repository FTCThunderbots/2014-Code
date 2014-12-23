// background.h
// Header file for background.c

#define BACKGROUND_INCLUDEGUARD

#ifndef DEBUG_INCLUDEGUARD
#include "debug.c"
#endif

#ifndef MOVEMENT_INCLUDEGUARD
#include "movement.c"
#endif

#ifndef NXT_INCLUDEGUARD
#include "nxt.c"
#endif

void initializeRobot();
void initializeAPI();
task background();

static void suppressUnreferencedWarnings();
