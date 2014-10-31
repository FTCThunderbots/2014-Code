// #include statements
#include "JoystickDriver.c"
#include "unitConverter.c"

float x = 0.0, z = 0.0;
float orientation = 0.0;

static float updateX(float degrees) {
	return (float)(x + sin(degrees));
}

static float updateZ(float degrees) {
	return (float)(x + cos(degrees));
}

static float getOrientation(float degrees) {
	// will return off a base of 4
	return (float)((orientation + cos(degrees)) % 4);
}

static float * UpdateCoords(float degrees, length CIRCUM_TYPE) {
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
		float changedX = updateX(degrees);
		float changedZ = updateZ(degrees);
		float changedOrientation = getOrientation(degrees);

		float change[] = {changedX, changedZ, changedOrientation};

		return &change[0];
}
