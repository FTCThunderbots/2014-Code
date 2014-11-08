// debug.c
// Code used for debugging any functional top-level code

#include "debug.h"

static string consoleLines[8];



//#ifdef DEBUG_STREAM_ON

void updateDebugStream() {
   nxtDisplayTextLine(0, debugStreamType1, debugStreamLine1);
   nxtDisplayTextLine(1, debugStreamType2, debugStreamLine2);
   nxtDisplayTextLine(2, debugStreamType3, debugStreamLine3);
   nxtDisplayTextLine(3, debugStreamType4, debugStreamLine4);
   nxtDisplayTextLine(4, debugStreamType5, debugStreamLine5);
   nxtDisplayTextLine(5, debugStreamType6, debugStreamLine6);
   nxtDisplayTextLine(6, debugStreamType7, debugStreamLine7);
   nxtDisplayTextLine(7, debugStreamType8, debugStreamLine8);
}

//#else // #ifdef DEBUG_STREAM_ON, aka debug stream is off

//void updateDebugStream() {
   // do nothing
//}

//#endif

void printConsole(string toPrint) {
	int i;
	for (i = 1; i <= 7; i++)
		consoleLines[i-1] = consoleLines[i];
	consoleLines[7] = toPrint;
	for (i = 0; i < 7; i++)
		nxtDisplayTextLine(0, consoleLines[i]);
}
