// PID.c
//This is where we code the PID.

void correctLinear(int speed) {

}

void correctRotate(int posSpeed) {

}

#ifndef setting_twoMotors
void correctSwing(int speed) {
	if (motor[leftmotor_1] != 0) {
		if (leftEnc1 < leftEnc2) {
			if (abs(motor[leftmotor_1]) < abs(speed) - 4)
				motor[leftmotor_1] += CORRECTION_CONSTANT;
			else
				motor[leftmotor_2] -= CORRECTION_CONSTANT;
		} else if (leftEnc1 > leftEnc2) {
			if (abs(motor[leftmotor_2]) < abs(speed) - 4)
				motor[leftmotor_2] += CORRECTION_CONSTANT;
			else
				motor[leftmotor_1] -= CORRECTION_CONSTANT;
		}
	} else {
		if (rightEnc1 < rightEnc2) {
			if (abs(motor[rightmotor_1]) < abs(speed) - 4)
				motor[rightmotor_1] += CORRECTION_CONSTANT;
			else
				motor[rightmotor_2] -= CORRECTION_CONSTANT;
		} else if (rightEnc1 > rightEnc2) {
			if (abs(motor[rightmotor_2]) < abs(speed) - 4)
				motor[rightmotor_2] += CORRECTION_CONSTANT;
			else
				motor[rightmotor_1] -= CORRECTION_CONSTANT;
		}
	}
}
#endif
