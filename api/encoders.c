// encoders.c
// Contains code for accessing encoder values at the lowest possible level

// Accessing encoder values

long getEncoder_left1() {
	return nMotorEncoder[leftmotor_1];
}

long getEncoder_right1() {
	return nMotorEncoder[rightmotor_1];
}

long getEncoder_left2() {
	#ifndef setting_twoEncoders
	return nMotorEncoder[leftmotor_2];
	#else
	return getEncoder_left1();
	#endif
}

long getEncoder_right2() {
	#ifndef setting_twoEncoders
	return nMotorEncoder[rightmotor_2];
	#else
	return getEncoder_right1();
	#endif
}

// Setting encoder values
// I hope we never have to use these, but they're here just in case. (Zach)

void setEncoder_left1(long val) {
	nMotorEncoder[leftmotor_1] = val;
}

void setEncoder_right1(long val) {
	nMotorEncoder[rightmotor_1] = val;
}

void setEncoder_left2(long val) {
	#ifndef setting_twoEncoders
	nMotorEncoder[leftmotor_2] = val;
	#else
	setEncoder_left1(val);
	#endif
}

void setEncoder_right2(long val) {
	#ifndef setting_twoEncoders
	nMotorEncoder[rightmotor_2] = val;
	#else
	setEncoder_right1(val);
	#endif
}

// Shortcut to getting and setting encoder values
// Potentially useful for iterating through all the encoders?
// Try to avoid literal string arguments, because the non-shortcut version is faster

long getEncoder(String enc) {
	if (enc == "l1")
		return getEncoder_left1();
	else if (enc == "r1")
		return getEncoder_right1();
	else if (enc == "l2")
		return getEncoder_left2();
	else if (enc == "r2")
		return getEncoder_right2();
	else
		return -1;
}
		
void setEncoder(String enc, long val) {
	if (enc == "l1")
		setEncoder_left1(val);
	else if (enc == "r1")
		setEncoder_right1(val);
	else if (enc == "l2")
		setEncoder_left2(val);
	else if (enc == "r2")
		setEncoder_right2(val);
}

// Unit conversions
long degreesToTicks(float degrees) {
	return degreesToTurnTicks(degrees);
}

long degreesToTurnTicks(float degrees) {
	return ENCODER_TICKS_PER_TURN_DEGREE * degrees;
}

long degreesToSwingTicks(float degrees) {
	return ENCODER_TICKS_PER_SWING_DEGREE * degrees;
}


long inchesToTicks(float inches) {
	return inchesToDriveTicks(inches)
}

long inchesToDriveTicks(float inches) {
	return ENCODER_TICKS_PER_DRIVE_INCH * inches;
}

long inchesToStrafeTicks(float inches) {
	return 	ENCODER_TICKS_PER_STRAFE_INCH * inches;
}


long centimetersToTicks(float centimeters) {
	return centimetersToDriveTicks(centimeters);
}

long centimetersToDriveTicks(float centimeters) {
	return inchesToTicks(cmToIn(centimeters));
}

long centimetersToStrafeTicks(float centimeters) {
	return inchesToStrafeTicks(cmToIn(centimeters));
}