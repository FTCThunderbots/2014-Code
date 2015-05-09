/* debug.c | Functions and tasks used for debugging other features of the code
 * Copyright (C) 2015 Thunderbots-5604
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "debug.h"

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

#else //debug stream is off

void updateDebugStream() {
	// do nothing
}

#endif //debug stream

#ifdef DEBUG_CONSOLE_ON

void updateDebugConsole() {
	for (int i = 0; i < 7; i++)
		if (!streamDefined[i])
			nxtDisplayTextLine(i, consoleLines[i]);
}

void initDebugConsole() {
	static bool streamDefined[8];
	#ifdef debugStreamLine1
	streamDefined[0] = true;
	#endif
	#ifdef debugStreamLine2
	streamDefined[1] = true;
	#endif
	#ifdef debugStreamLine3
	streamDefined[2] = true;
	#endif
	#ifdef debugStreamLine4
	streamDefined[3] = true;
	#endif
	#ifdef debugStreamLine5
	streamDefined[4] = true;
	#endif
	#ifdef debugStreamLine6
	streamDefined[5] = true;
	#endif
	#ifdef debugStreamLine7
	streamDefined[6] = true;
	#endif
	#ifdef debugStreamLine8
	streamDefined[7] = true;
	#endif
}

#else // debug console is off

void updateDebugConsole() {
	// do nothing
}

void initDebugConsole() {
	// do nothing
}

#endif // debug console

void printConsole(string toPrint) {
	for (int i = 1; i <= 7; i++)
		consoleLines[i-1] = consoleLines[i];
	consoleLines[7] = toPrint;
}

