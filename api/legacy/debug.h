/* debug.h | Header file for debug.c
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

#define DEBUG_INCLUDEGUARD

#ifndef ENCODERS_INCLUDEGUARD
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
