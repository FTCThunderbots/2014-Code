/* background.h | Header file for background.c
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

#define BACKGROUND_INCLUDEGUARD

#ifndef MOVEMENT_INCLUDEGUARD
#include "movement.c"
#endif

#ifndef NXT_INCLUDEGUARD
#include "nxt.c"
#endif

void initializeRobot();
void initializeAPI();
task background();

static void suppressUnreferencedWarnings(int a);
