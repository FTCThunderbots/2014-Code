#include "../api/api.c"
#include "coord.h"

#define COORD_INCLUDEGAURD	true

float x, z, orientation;

void setDefaults() {
	x = 0.0;
	z = 0.0;
	orientation = 0.0;
}

void updateDirection(float degrees) {
	orientation = (180/PI)*orientation;
	orientation = (orientation + degrees) % 360 - PI;
	orientation = degreesToRadians(orientation);
}

void updateCoords(float distance) {
	x += distance * sin(orientation);
	z += distance * cos(orientation);
}

float readValues(char value) {
	if (value == 'x')
		return x;
	else if (value == 'z')
		return z;
	else
		return orientation;
}
