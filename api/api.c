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
#include "background.c"
#include "functions.c"
#include "math.c"
#include "movement.c"
#include "ruler.c"
#include "sensors.h"
#include "settings.c"
#include "simplemovement.c"
#include "timer.c"

#include "JoystickDriver.c"

task main() {
	//may need to rephrase based on how wide the NXT screen is
	nxtDisplayCenteredTextLine(2, "This is the API");
	nxtDisplayCenteredTextLine(3, "There's no executable code here");
	nxtDisplayCenteredTextLine(5, "Please see documentation");
	nxtDisplayCenteredTextLine(6, "Or ask someone else");
	wait1Msec(20000);
}

#endif /* include guard */

// ALL THE CODE BELOW IS HOMELESS
// BUT WITH YOUR HELP, WE CAN SAVE IT
// AKA please find a better file for this code

#warn "This code needs a better home!"
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
