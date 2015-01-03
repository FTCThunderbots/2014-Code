// sensors.h
// Header file for sensors.c

#define SENSORS_INCLUDEGUARD

#include "Xander_Drivers\drivers\hitechnic-sensormux.h" //We will be using these drivers for all of our sensors. It is the sensor multiplexor
#include "Xander_Drivers\drivers\hitechnic-compass.h" // Compass sensor, if enabled
#include "Xander_Drivers\drivers\hitechnic-irseeker-v2.h" // IR seeker

void initSensors(); //called by initializeAPI()
static void initCompass();
static void initIRSeeker();

#ifdef COMPASS
int getHeading();
int getRelativeHeading();
int setCompassTarget();
#endif

#ifdef INFRARED
int getIRpos();
#endif
