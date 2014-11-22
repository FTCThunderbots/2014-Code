// debug.h
// Header file for debug.c

#define DEBUG_INCLUDEGAURD

#ifndef ENCODERS_INCLUDEGAURD
#include "encoders.c"
#endif

// Define types

#ifndef debugStreamType1
#define debugStreamType1 "%d"
#endif

#ifndef debugStreamType2
#define debugStreamType2 "%d"
#endif

#ifndef debugStreamType3
#define debugStreamType3 "%d"
#endif

#ifndef debugStreamType4
#define debugStreamType4 "%d"
#endif

#ifndef debugStreamType5
#define debugStreamType5 "%d"
#endif

#ifndef debugStreamType6
#define debugStreamType6 "%d"
#endif

#ifndef debugStreamType7
#define debugStreamType7 "%d"
#endif

#ifndef debugStreamType8
#define debugStreamType8 "%d"
#endif

void updateDebugStream();
void updateDebugConsole();
void printConsole(string toPrint);
void initDebugConsole();
