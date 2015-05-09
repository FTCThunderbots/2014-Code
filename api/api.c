/* api.c | Master include file for the entire api
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

// If we're using two-wheel mode, only use two encoders
// This should be obvious

#ifdef setting_twoMotors
#ifndef setting_twoEncoders
#define setting_twoEncoders
#endif
#endif

#ifndef JOYSTICKDRIVER_INCLUDEGUARD
#include "JoystickDriver.c"
#define JOYSTICKDRIVER_INCLUDEGUARD
#endif

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif

#ifndef BACKBOARD_INCLUDEGUARD
#include "backboard.c"
#endif

#ifndef BACKGROUND_INCLUDEGUARD
#include "background.c"
#endif

#ifndef COORDINATES_INCLUDEGUARD
#include "coordinates.c"
#endif

#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif

#ifndef GRAB_INCLUDEGUARD
#include "grab.c"
#endif

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

#ifndef MOVEMENT_INCLUDEGUARD
#include "movement.c"
#endif

#ifndef NXT_INCLUDEGUARD
#include "nxt.c"
#endif

#ifndef PID_INCLUDEGUARD
#include "pid.c"
#endif

#ifndef SENSORS_INCLUDEGUARD
#include "sensors.c"
#endif

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

#ifndef TELEOP_INCLUDEGUARD
#include "teleop.c"
#endif

#ifndef TIMER_INCLUDEGUARD
#include "time.c"
#endif
