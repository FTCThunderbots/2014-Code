// #include statements
#include "math.c"
#include "JoystickDriver.c"
#include "api.c"
#include "unit_converter.c"
//#pragma

float x = 0.0, z = 0.0;

typedef enum {INCHES, FEET, CENTIMETER, METER} length_t;

static void UpdateCoords(float degrees, length_t CIRCUM_TYPE) {
		/*
			1. Divide ticks by 1440 then multiply by circumference (Gives you how far it moved in the units
			you have used for circumference.
			2. Convert the units to feet.
		*/
		byte ticks = nMotorEncoder[;
		float changeCoord = (ticks / 1440) * convertUnits(CIRCUM_TYPE, FEET, degrees);
}

#pragma //put the nameOfMotor here
nMotorEncoder[nameOfMotor];
