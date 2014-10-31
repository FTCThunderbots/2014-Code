// These
typedef enum {INCHES, FEET, CENTIMETER, METER} length_t;

// start of conversion functions (do not directly call)
// please use the convertUnits(int,int,float) function.
static float inchesConvert(length_t PARAM, float input) {
	float output;
	if (PARAM == INCHES)
		return input;
	else if (PARAM == FEET)
		output = input / 12;
	else if (PARAM == CENTIMETER)
		return input * 2.54;
	else if (PARAM == METER)
		return (input * 2.54) / 1000;
	return 0;
}

static float feetConvert(length_t PARAM, float input) {
	if (PARAM == INCHES)
		return input * 12;
	else if (PARAM == FEET)
		return input;
	else if (PARAM == CENTIMETER)
		return (input * 12) * 2.54;
	else if (PARAM == METER)
		return ((input * 12) * 2.54) / 1000;
}

static float centimeterConvert(length_t PARAM, float input) {
	if (PARAM == INCHES)
		return input / 2.54;
	else if (PARAM == FEET)
		return (input / 2.54) / 12;
	else if (PARAM == CENTIMETER)
		return input;
	else if (PARAM == METER)
		return input/1000;
}

static float meterConvert(length_t PARAM, float input) {
	if (PARAM == INCHES)
		return (input / 1000) / 2.54;
	else if (PARAM == FEET)
		return ((input / 1000) / 2.54) / 12;
	else if (PARAM == CENTIMETER)
		return input / 1000;
	else if (PARAM == METER)
		return input;
}
// end of conversion blocks

float convertUnits(length_t UNIT, length_t PARAM, float input) {
	if (UNIT == INCHES)
		return inchesConvert(PARAM, input);
	else if (UNIT == FEET)
		return feetConvert(PARAM, input);
	else if (UNIT == CENTIMETER)
		return centimeterConvert(PARAM, input);
	else if (UNIT == METER)
		return meterConvert(PARAM, input);
}
