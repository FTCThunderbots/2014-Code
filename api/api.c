// api.c
// Contains imports for all api files

// If we're using two-wheel mode, only use two encoders
// This should be obvious

#ifdef setting_twoMotors
#ifndef setting_twoEncoders
#define setting_twoEncoders
#endif
#endif


#ifndef JOYSTICKDRIVER_INCLUDEGAURD
#include "JoystickDriver.c"
#define JOYSTICKDRIVER_INCLUDEGAURD
#endif

// Please keep this list alphabetized

#ifndef BACKGROUND_INCLUDEGAURD
#include "background.c"
#endif

#ifndef DEBUG_INCLUDEGAURD
#include "debug.c"
#endif

#ifndef DISTANCES_INCLUDEGAURD
#include "distances.c"
#endif

#ifndef NXT_INCLUDEGAURD
#include "nxt.c"
#endif

#ifndef FUNCTIONS_INCLUDEGAURD
#include "functions.c"
#endif

#ifndef MATH_INCLUDEGAURD
#include "math.c"
#endif

#ifndef MOVEMENT_INCLUDEGAURD
#include "movement.c"
#endif

#ifndef RULER_INCLUDEGAURD
#include "ruler.c"
#endif

#ifndef SENSORS_INCLUDEGAURD
#include "sensors.c"
#endif

#ifndef SETTINGS_INCLUDEGAURD
#include "settings.c"
#endif

#ifndef SIMPLEMOVEMENT_INCLUDEGAURD
#include "simplemovement.c"
#endif

#ifndef TIMER_INCLUDEGAURD
#include "timer.c"
#endif
