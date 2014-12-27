// PID.c
//This is where we code the PID.

void correctLinear() {

}

void correctRotate() {

}

#ifndef setting_twoMotors
void correctSwing(int speed) {
	if (motor[leftmotor_1] != 0) {
		if (leftEnc1 < leftEnc2) {
			if (motor[leftmotor_1] < speed - 4)
				motor[leftmotor_1] += CORRECTION_CONSTANT;
			else
				motor[leftmotor_2] -= CORRECTION_CONSTANT;
		} else if (leftEnc1 > leftEnc2) {
			if (motor[leftmotor_2] < speed - 4)
				motor[leftmotor_2] += CORRECTION_CONSTANT;
			else
				motor[leftmotor_1] -= CORRECTION_CONSTANT;
		}
	} else {
		if (rightEnc1 < rightEnc2) {
			if (motor[rightmotor_1] < speed - 4)
				motor[rightmotor_1] += CORRECTION_CONSTANT;
			else
				motor[rightmotor_2] -= CORRECTION_CONSTANT;
		} else if (rightEnc1 > rightEnc2) {
			if (motor[rightmotor_2] < speed - 4)
				motor[rightmotor_2] += CORRECTION_CONSTANT;
			else
				motor[rightmotor_1] -= CORRECTION_CONSTANT;
		}
	}
}
#endif
