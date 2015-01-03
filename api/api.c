// api.c
// Contains imports for all api files

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

//#ifndef COORD_INCLUDEGUARD
//#include "coord.c"
//#endif

#ifndef DEBUG_INCLUDEGUARD
#include "debug.c"
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
#include "timer.h"
#endif
