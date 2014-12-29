// PID.c
//This is where we code the PID.

#include "PID.h"

void correctLinear(int speed) {
	// the P (proportional)
	int turnPower = nMotorEncoder[rightmotor_1] - nMotorEncoder[leftmotor_1];
	turnPower = BOUND((int)(turnPower*Kp), -10, 10);


	motor[leftmotor_1] = BOUND(speed + turnPower, -MOTOR_MAX_POWER, MOTOR_MAX_POWER);
	motor[rightmotor_1] = BOUND(speed - turnPower, -MOTOR_MAX_POWER, MOTOR_MAX_POWER);
	#ifndef setting_twoMotors
	motor[leftmotor_2] = BOUND(speed + turnPower, -MOTOR_MAX_POWER, MOTOR_MAX_POWER);
	motor[rightmotor_2] = BOUND(speed - turnPower, -MOTOR_MAX_POWER, MOTOR_MAX_POWER);
	#endif
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

void pid_zeroize(PID* pid) {
    // set prev and integrated error to zero
    pid->prev_error = 0;
    pid->int_error = 0;
}

void pid_update(PID* pid, float curr_error, float dt) {
    float diff;
    float p_term;
    float i_term;
    float d_term;

    // integration with windup guarding
    pid->int_error += (curr_error * dt);
    if (pid->int_error < -(pid->windup_guard))
        pid->int_error = -(pid->windup_guard);
    else if (pid->int_error > pid->windup_guard)
        pid->int_error = pid->windup_guard;

    // differentiation
    diff = ((curr_error - pid->prev_error) / dt);

    // scaling
    p_term = (pid->proportional_gain * curr_error);
    i_term = (pid->integral_gain     * pid->int_error);
    d_term = (pid->derivative_gain   * diff);

    // summation of terms
    pid->control = p_term + i_term + d_term;

    // save current error as previous error for next iteration
    pid->prev_error = curr_error;
}
