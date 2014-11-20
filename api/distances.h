// distances.h
// Header file for distances.c

#define DISTANCES_INCLUDEGAURD

#ifndef RULER_INCLUDEGAURD
#include "ruler.c"
#endif

void waitDriveTicks(long ticks);
void waitStrafeTicks(long ticks);
void waitRotateTicks(long ticks);
void waitSwingTicks(long ticks);

void waitDriveInches(float inches);
void waitStrafeInches(float inches);
void waitRotateDegrees(float degrees);
void waitSwingDegrees(float degrees);