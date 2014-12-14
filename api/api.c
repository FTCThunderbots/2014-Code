// api.c
// Contains imports for all api files

// If we're using two-wheel mode, only use two encoders
// This should be obvious

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

// Please keep this list alphabetized

#ifndef BACKGROUND_INCLUDEGUARD
#include "background.c"
#endif

#ifndef DEBUG_INCLUDEGUARD
#include "debug.c"
#endif

#ifndef NXT_INCLUDEGUARD
#include "nxt.c"
#endif

#ifndef FUNCTIONS_INCLUDEGUARD
#include "functions.c"
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

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

#ifndef TIMER_INCLUDEGUARD
#include "timer.h"
#endif
