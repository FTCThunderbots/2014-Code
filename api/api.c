// api.c
// Contiains imports for all api files

#ifndef API_INCLUDEGUARD
#define API_INCLUDEGUARD
// files will only be included once, preventing infinite recursion

#ifdef CONFIGFILE
#include CONFIGFILE
#else
#include "../config/default_config.c"
#endif
//if user has defined a custom config file, include it
//else, include default config

// Please keep this list alphabetized
#ifndef BACKGROUND_INCLUDEGAURD
#include "background.c"
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

#endif /* include guard */

// ALL THE CODE BELOW IS HOMELESS
// BUT WITH YOUR HELP, WE CAN SAVE IT
// AKA please find a better file for this code

#warn "(api.c) This code needs a better home!"
/* long inchesToTicks(int inches) {
	return PI*WHEEL_DIAMETER/1440*inches;
}

long inchesToTicks(float inches) {
	return PI*WHEEL_DIAMETER/1440*inches;
}

long inchesToTicks(byte inches) {
	return PI*WHEEL_DIAMETER/1440*inches;
}

byte centimetersToInches(byte centimeters) {
	return centimeters/CM_PER_IN;
}

int centimetersToInches(int centimeters) {
	return centimeters/CM_PER_IN;
}

float centimetersToInches(float centimeters) {
	return centimeters/CM_PER_IN;
}

long centimetersToTicks(byte centimeters) {
	return inchesToTicks(centimetersToInches(centimeters));
}

long centimetersToTicks(int centimeters) {
	return inchesToTicks(centimetersToInches(centimeters));
}

long centimetersToTicks(float centimeters) {
	return inchesToTicks(centimetersToInches(centimeters));
} */
