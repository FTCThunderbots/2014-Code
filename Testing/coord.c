#include "api.c"
#include "coord.h"

#define COORD_INCLUDEGAURD	true

float x, z, orientation;
x = 0.0;
z = 0.0;
orientation = 90.0;

void updateDirection(float degrees) {
	orientation = (180 / PI) * orientation + degrees;
	orientation = degreesToRadians(orientation);
}

void updateCoords(float distance) {
	x = distance * sin(orientation) + x;
	z = distance * cos(orientation) + z;
}

float readValues(char value) {
	if (value == 'x')
		return x;
	else if (value == 'z')
		return z;
	else
		return orientation;
}
