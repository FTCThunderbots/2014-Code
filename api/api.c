// api.c
// Contains imports for all api files

// If we're using two-wheel mode, only use two encoders
// This should be obvious

#warn "(settings.c) Please set time vals for auto grabbing and auto backboard"

#ifdef setting_twoMotors
#ifndef setting_twoEncoders
#define setting_twoEncoders
#endif
#endif

#ifdef setting_noMotors
#ifndef setting_noEncoders
#define setting_noEncoders
#endif
#endif

#ifndef JOYSTICKDRIVER_INCLUDEGUARD
#include "JoystickDriver.c"
#define JOYSTICKDRIVER_INCLUDEGUARD
#endif

#ifndef TIMER_INCLUDEGUARD
#include "timer.h"
#endif

#ifndef ENCODERS_INCLUDEGUARD
#include "encoders.c"
#endif

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

#ifndef BACKGROUND_INCLUDEGUARD
#include "background.c"
#endif

#ifndef DEBUG_INCLUDEGUARD
#include "debug.c"
#endif

#ifndef NXT_INCLUDEGUARD
#include "nxt.c"
#endif

#ifndef GRAB_INCLUDEGUARD
#include "grab.c"
#endif

#ifndef BACKBOARD_INCLUDEGUARD
#include "backboard.c"
#endif

#ifndef TELEOP_INCLUDEGUARD
#include "teleop.c"
#endif

#ifndef MATH_INCLUDEGUARD
#include "math.c"
#endif

#ifndef MOVEMENT_INCLUDEGUARD
#include "movement.c"
#endif

#ifndef SENSORS_INCLUDEGUARD
#include "sensors.c"
#endif

#ifndef SETTINGS_INCLUDEGUARD
#include "settings.c"
#endif
