// api.c
// Contiains imports for all api files

//#ifndef API_INCLUDEGUARD
//#define API_INCLUDEGUARD
// files will only be included once, preventing infinite recursion

// If we're using two-wheel mode, only use two encoders
// This should be obvious
#ifdef setting_twoMotors
#ifndef setting_twoEncoders
#define setting_twoEncoders
#endif
#endif

#ifndef compass_name
#define compass_name NULL
#endif

// Please keep this list alphabetized lol no dont do that



#ifndef BACKGROUND_INCLUDEGAURD
#include "background.c"
#endif

#ifndef DEBUG_INCLUDEGAURD
#include "debug.c"
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

#include "JoystickDriver.c"

//#endif /* include guard */

// ALL THE CODE BELOW IS HOMELESS
// BUT WITH YOUR HELP, WE CAN SAVE IT
// AKA please find a better file for this code
