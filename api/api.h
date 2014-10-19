// api.h
// Contiains imports for all api files

#ifdef configfile
#include configfile
#else
#include "config.c"
#endif
//if user has defined a custom config file, include it
//else, include default config

// Please keep this list alphabetized
#include "functions.c"
#include "math.c"
#include "movement.c"
#include "ruler.c"
#include "sensors.c"
#include "settings.c"
#include "simplemovement.c"
#include "timer.c"

// and everyone's favorite...
#include "JoystickDriver.c"