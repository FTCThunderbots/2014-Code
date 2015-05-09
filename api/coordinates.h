/* coordinates.h | Header file for coordinates.c
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

#define COORD_INCLUDEGUARD

//#warn "Coordinate functions are not finished. DO NOT USE."

#ifndef SENSORS_INCLUDEGUARD
#include "sensors.c"
#endif

#ifndef SIMPLEMOVEMENT_INCLUDEGUARD
#include "simplemovement.c"
#endif

void updateDirection(float degrees);
void updateCoords(float distance);
void gotoCoords(float newX, float newZ, float newO);
float readValues(char value);		/*'x' for x 'z' for z 'o' for orientation*/
void rotateWithOrientation(int degrees, byte power);
void moveWithDirection(float distance, byte power);
void moveWithDirection(float distance, byte power, int stopSeconds);
void setCoords(float newX, float newZ, float newO);
void swingWithCoords(float degrees, byte direction, byte power);
