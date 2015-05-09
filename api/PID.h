/* pid.h | Header file for pid.c
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

#define PID_INCLUDEGUARD

#define BOUND(n, l, h) (((n)<(l)) ? (l) : ((n)>(h)) ? (h) : (n))

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

typedef struct {
	float windup_guard;
	float proportional_gain;
	float integral_gain;
	float derivative_gain;
	float prev_error;
	float int_error;
	float control;
} PID;

void moveFor(int ticks, int speed);
void moveFor(int ticks, int speed, int stopSeconds);
void swingFor(int ticks, int direction, int speed);

void pid_zeroize(PID* pid);
void pid_update(PID* pid, float curr_error, float dt);

#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif
