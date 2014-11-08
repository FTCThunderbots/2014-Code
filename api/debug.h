// debug.h
// Header file for debug.c

#define DEBUG_INCLUDEGAURD

#ifdef DEBUG_STREAM_ON

#ifndef debugStreamLine1
#define debugStreamLine1 0
#define debugStreamType1 "%d"
#endif

#ifndef debugStreamLine2
#define debugStreamLine2 0
#define debugStreamType2 "%d"
#endif

#ifndef debugStreamLine3
#define debugStreamLine3 0
#define debugStreamType3 "%d"
#endif

#ifndef debugStreamLine4
#define debugStreamLine4 0
#define debugStreamType4 "%d"
#endif

#ifndef debugStreamLine5
#define debugStreamLine5 0
#define debugStreamType5 "%d"
#endif

#ifndef debugStreamLine6
#define debugStreamLine6 0
#define debugStreamType6 "%d"
#endif

#ifndef debugStreamLine7
#define debugStreamLine7 0
#define debugStreamType7 "%d"
#endif

#ifndef debugStreamLine8
#define debugStreamLine8 0
#define debugStreamType8 "%d"
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

#endif //ifdef DEBUG_STREAM_ON

void updateDebugStream();
void printConsole(string toPrint);
