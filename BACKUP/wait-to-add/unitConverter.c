// These are acceptable values
typedef enum {INCHES, FEET, CENTIMETER, METER} length;

// start of conversion functions (do not directly call)
// please use the convertUnits(int,int,float) function.
static float inchesConvert(length PARAM, float input) {
	float output = 0.0;

	if (PARAM == 0) {
		return input;
	} else if (PARAM == 1) {

		// do inches to feet conversion
		output = input / 12;
	} else if (PARAM == 2) {

		// do inches to centimeter conversion
		output = input * 2.54;
	} else if (PARAM == 3) {

		// do inches to meter conversion
		output = (input * 2.54) / 1000;
	}

	return output;
}

static float feetConvert(length PARAM, float input) {
	float output = 0.0;

	if (PARAM == 0) {

		// do feet to inches
		output = input * 12;

	} else if (PARAM == 1) {

		// do feet to feet (remains the same)
		return input;

	} else if (PARAM == 2) {

		// do feet to centimeters
		output = (input * 12) * 2.54;

	} else if (PARAM == 3) {

		// do feet to meters
		output = ((input * 12) * 2.54) / 1000;

	}

	return output;
}

static float centimeterConvert(length PARAM, float input) {
	float output = 0.0;

	if (PARAM == 0) {

		// do centimeter to inches
		output = input / 2.54;

	} else if (PARAM == 1) {

		// do centimeter to feet
		output = (input / 2.54) / 12;

	} else if (PARAM == 2) {

		// do centimeter to centimeter (remains the same)
		return input;

	} else if (PARAM == 3) {

		// do centimeter to meter
		output = input / 1000;

	}

	return output;
}

static float meterConvert(length PARAM, float input) {
	float output = 0.0;

	if (PARAM == 0) {

		// do meter to inches
		output = (input / 1000) / 2.54;

	} else if (PARAM == 1) {

		// do meter to feet
		output = ((input / 1000) / 2.54) / 12;

	} else if (PARAM == 2) {

		// do meter to centimeter
		output = input / 1000;

	} else if (PARAM == 3) {

		// do meter to meter (remains the same)
		return input;

	}

	return output;
}
// end of conversion blocks

float convertUnits(length UNIT, length PARAM, float input)
{
	/*
		If unit == INCH (1) then call inchesConvert
	*/
	float output;
	if (UNIT == 0) {
		output = inchesConvert(PARAM, input);
	}	else if (UNIT == 1) {
		output = feetConvert(PARAM, input);
	} else if (UNIT == 2) {
		output = centimeterConvert(PARAM, input);
	} else if (UNIT == 3) {
		output = meterConvert(PARAM, input);
	}

	return output;
}
