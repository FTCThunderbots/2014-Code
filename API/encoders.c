// encoders.c
// Contains code for accessing encoder values at the lowest possible level

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