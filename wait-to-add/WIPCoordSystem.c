// #include statements
#include "JoystickDriver.c"
#include "unitConverter.c"

#define XCOORD 0
#define ZCOORD 1
#define DEG	2

float x = 0.0, z = 0.0;
float orientation = 0.0;

static float updateX(float degrees, float distanceTraveled) {
	return (float)(x + sin(degrees) * distanceTraveled);
}

static float updateZ(float degrees, float distanceTraveled) {
	return (float)(z + cos(degrees) * distanceTraveled);
}

static float getOrientation(float degrees) {
	// will return off a base of 4
	return (float)((orientation + cos(degrees)) % 4);
}

static void updateCoords(float degrees, length CIRCUM_TYPE) {
		/*
			1. Divide ticks by 1440 then multiply by circumference (Gives you how far it moved in the units
			you have used for circumference.
			2. Convert the units to feet.
		*/
		byte ticks = nMotorEncoder[NULL]; /* Will remain NULL until motor is known.*/
		float changeCoord = (ticks / 1440) * convertUnits(CIRCUM_TYPE, FEET, degrees);

		/*
		*First I take the degrees and convert to radians.
		*Next, I'll use sin(rad) += x
		*/

		degrees = degreesToRadians(degrees);
		degrees *= changeCoord;
		float changedX = updateX(degrees, changeCoord);
		x += changedX;
		float changedZ = updateZ(degrees, changeCoord);
		y += changedZ;
		float changedOrientation = getOrientation(degrees);
		orientation += changedOrientation;

		float change = {changedX, changedZ, changedOrientation};
}

static float getCoordinateValue(int value) {
	if (value == 0) {
			return x;
	} else if (value == 1) {
			return z;
	} else if (value == 2) {
			return orientation;
	}
}
