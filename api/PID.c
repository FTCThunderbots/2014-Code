// PID.c
//This is where we code the PID.

#include "PID.h"

static int prev_time = 0;

void moveFor(int ticks, int speed, bool usePID) { //speed is positive for rotating
	//this will work for rotating in place and linear driving (forwards and backwards)
	//might also work for strafing
	resetEncoders();
	int startTime = time1[T1];
	if (usePID) {
		ClearTimer(T1);
		PID pid;
		pid_zeroize(&pid);
		if (sgn(motor[leftmotor_1]) == sgn(motor[rightmotor_1])) //we are rotating
			while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {
				pid_update(&pid, abs(rightEnc1) - abs(leftEnc1), time1(T1) - prev_time);
				prev_time = time1(T1);
				motor[leftmotor_1] = speed + sgn(motor[leftmotor_1])*pid.control;
				motor[rightmotor_1] = speed - sgn(motor[rightmotor_1])*pid.control;
				#ifndef setting_twoMotors
				motor[leftmotor_2] = speed + sgn(motor[leftmotor_2])*pid.control;
				motor[rightmotor_2] = speed - sgn(motor[rightmotor_1])*pid.control;
				#endif
				wait10Msec(1);
			}
		else //we are driving
			while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {
				pid_update(&pid, abs(rightEnc1) - abs(leftEnc1), time1(T1) - prev_time);
				prev_time = time1(T1);
				motor[leftmotor_1] = speed - sgn(motor[leftmotor_1])*pid.control;
				motor[rightmotor_1] = -speed - sgn(motor[rightmotor_1])*pid.control;
				#ifndef setting_twoMotors
				motor[leftmotor_2] = speed - sgn(motor[leftmotor_2])*pid.control;
				motor[rightmotor_2] = -speed - sgn(motor[rightmotor_2])*pid.control;
				#endif
				wait10Msec(1);
			}
	} else //no PID
		while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {}
	prev_time = 0;
}

void moveFor(int ticks, int speed, bool usePID, int stopSeconds) { //speed is positive for rotating
	//this will work for rotating in place and linear driving (forwards and backwards)
	//might also work for strafing
	resetEncoders();
	int startTime = time1[T1];
	if (usePID) {
		ClearTimer(T1);
		PID pid;
		pid_zeroize(&pid);
		if (sgn(motor[leftmotor_1]) == sgn(motor[rightmotor_1])) //we are rotating
			while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {
				pid_update(&pid, abs(rightEnc1) - abs(leftEnc1), time1(T1) - prev_time);
				prev_time = time1(T1);
				motor[leftmotor_1] = speed + sgn(motor[leftmotor_1])*pid.control;
				motor[rightmotor_1] = speed - sgn(motor[rightmotor_1])*pid.control;
				#ifndef setting_twoMotors
				motor[leftmotor_2] = speed + sgn(motor[leftmotor_2])*pid.control;
				motor[rightmotor_2] = speed - sgn(motor[rightmotor_1])*pid.control;
				#endif
				wait10Msec(1);
			}
		else { //we are driving 
			while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks)) {
				pid_update(&pid, abs(rightEnc1) - abs(leftEnc1), time1(T1) - prev_time);
				prev_time = time1(T1);
				motor[leftmotor_1] = speed - sgn(motor[leftmotor_1])*pid.control;
				motor[rightmotor_1] = -speed - sgn(motor[rightmotor_1])*pid.control;
				#ifndef setting_twoMotors
				motor[leftmotor_2] = speed - sgn(motor[leftmotor_2])*pid.control;
				motor[rightmotor_2] = -speed - sgn(motor[rightmotor_2])*pid.control;
				#endif
				wait10Msec(1);
			}
		}
	} else //no PID
		while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/4 < abs(ticks) && time1[T1] < startTime + 1000*stopSeconds) {}
	prev_time = 0;
}

void swingFor(int ticks, int direction, int speed, bool usePID) {
   resetEncoders();
   if (usePID) {
   	ClearTimer(T1);
   	PID pid;
   	pid_zeroize(&pid);
   	#ifndef setting_twoEncoders
   	while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/2 < abs(ticks)) {
     	//BE WARNED, THIS HAS NOT BEEN TESTED!!! IT PROBABLY DOES NOT WORK!!!
     	pid_update(&pid, (sgn(direction) == -1) ? rightEnc2 - rightEnc1 : leftEnc2 - leftEnc1, time1(T1) - prev_time);
     	// ^^^ calculates pid based on which side is moving
     	prev_time = time1(T1);
     	if (sgn(direction) == -1) {
       	motor[rightmotor_1] = -speed + sgn(speed)*pid.control;
       	motor[rightmotor_2] = -speed - sgn(speed)*pid.control;
     	} else {
	     	motor[leftmotor_1] = speed + pid.control;
     		motor[leftmotor_2] = speed - pid.control;
     	}
   	}
   	#else
   	while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/2 < abs(ticks)) {}
		#endif
	 } else
	   while ((abs(leftEnc1) + abs(leftEnc2) + abs(rightEnc1) + abs(rightEnc2))/2 < abs(ticks)) {}
   prev_time = 0;
}

void pid_zeroize(PID* pid) {
    // set prev and integrated error to zero
    pid->prev_error = 0;
    pid->int_error = 0;
    pid->windup_guard = INTEGRAL_CAP;
    pid->proportional_gain = Kp;
    pid->integral_gain = Ki;
    pid->derivative_gain = Kd;
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
    pid->control = BOUND(p_term + i_term + d_term, -MOTOR_MAX_POWER, MOTOR_MAX_POWER);

    // save current error as previous error for next iteration
    pid->prev_error = curr_error;
}
