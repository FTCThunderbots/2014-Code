/* background.c | The background processes
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

#include "background.h"

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

void initializeRobot() {
	halt();
	resetEncoders();
	nMotorEncoder[grab] = 1;
	nMotorEncoder[backboard] = 1;
}

void initializeAPI() {
	initSensors();
	//StartTask(matchStartListener);
	StartTask(background);
}

task background() {
	while (true) {
		//updateDebugStream(); //debug.c
		//updateDebugConsole();
		EndTimeSlice();
	}
}

static void suppressUnreferencedWarnings(int a) {
	a = BACKBOARD_MOTOR_UP_POS;
	a = BACKBOARD_MOTOR_DOWN_POS;
	a = DEFAULT_MOVE_POWER;
	StartTask(matchStartListener);
}
