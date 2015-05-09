/* sensors.h | Header file for sensors.c
 * Copyright (C) 2015 Thunderbots-5604
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#define SENSORS_INCLUDEGUARD

//#include "Xander_Drivers\drivers\hitechnic-sensormux.h" //We will be using these drivers for all of our sensors. It is the sensor multiplexor
//#include "Xander_Drivers\drivers\hitechnic-compass.h" // Compass sensor, if enabled
//#include "Xander_Drivers\drivers\hitechnic-irseeker-v2.h" // IR seeker

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
