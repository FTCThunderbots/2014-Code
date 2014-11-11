// debug.c
// Code used for debugging any functional top-level code

#include "debug.h"
#warn "(debug.c) remove the following line"
#include "timer.c"

static string consoleLines[8];

#ifdef DEBUG_STREAM_ON

void updateDebugStream() {
#ifdef debugStreamLine1
   nxtDisplayTextLine(0, debugStreamType1, debugStreamLine1);
#endif
#ifdef debugStreamLine2
   nxtDisplayTextLine(1, debugStreamType2, debugStreamLine2);
#endif
#ifdef debugStreamLine3
   nxtDisplayTextLine(2, debugStreamType3, debugStreamLine3);
#endif
#ifdef debugStreamLine4
   nxtDisplayTextLine(3, debugStreamType4, debugStreamLine4);
#endif
#ifdef debugStreamLine5
   nxtDisplayTextLine(4, debugStreamType5, debugStreamLine5);
#endif
#ifdef debugStreamLine6
   nxtDisplayTextLine(5, debugStreamType6, debugStreamLine6);
#endif
#ifdef debugStreamLine7
   nxtDisplayTextLine(6, debugStreamType7, debugStreamLine7);
#endif
#ifdef debugStreamLine8
   nxtDisplayTextLine(7, debugStreamType8, debugStreamLine8);
#endif
}

#else // debug stream is off

void updateDebugStream() {
   // do nothing
}

#endif

void printConsole(string toPrint) {
	for (int i = 1; i <= 7; i++)
		consoleLines[i-1] = consoleLines[i];
	consoleLines[7] = toPrint;
	for (int i = 0; i < 7; i++)
		nxtDisplayTextLine(0, consoleLines[i]);
}
