#define COORD_INCLUDEGUARD

#warn "Coordinate functions are not finished. DO NOT USE."

#ifndef SENSOR_INCLUDEGUARD
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
void setCoords(float newX, float newZ, float newO);
void swingWithCoords(float degrees, byte direction, byte power);
