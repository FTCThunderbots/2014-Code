// sensors.h
// Header file for sensors.c

#define SENSORS_INCLUDEGUARD

#include "Xander_Drivers\drivers\hitechnic-sensormux.h" //We will be using these drivers for all of our sensors
																										 		//This is the sensor multiplexor
#include "Xander_Drivers\drivers\hitechnic-irseeker-v2.h" // This is the IR seeker

#ifndef COORD_INCLUDEGUARD
#include "coord.h"
#endif

#warn "All compass code is depracated. We are using the Xander Drivers for all sensors"
#warn "The default drivers do not account for noise. See the /api/Xander_Drivers directory for example use."

int getCompassReading();
int calculateAverageReading(int samples);
void alignToCompassZero();
void alignToInitial();
void rotateDegreesImp(int degrees, byte power);
void swingDegreesImp(int degrees, byte direction, byte power);
void setInitial();
// compass_sensor.h Header File (Does indeed use the coordinate system!)
