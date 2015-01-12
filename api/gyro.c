// gyro.c
// Gyro Driver


#include "gyro.h"

float g_turnTarget;
// This function calibrates the gyro for zero offset and deadband.
void GyroCal(GYRO* gyro, int numSamples, int calInterval) {
    int i;
    int turnRate;
    int min, max;

    gyro->zeroOffset = 0;
    gyro->deadBand = 0;
    min = 1023;
    max = 0;

    for (i = 0; i < numSamples; i++) {
#ifdef HTSMUX_STATUS
        turnRate = (gyro->gyroFlags & GYROF_HTSMUX) ? HTGYROreadRot((tMUXSensor)gyro->sensorID) : HTGYROreadRot((tSensors)gyro->sensorID);
#else
        turnRate = HTGYROreadRot((tSensors)gyro->sensorID);
#endif
        gyro->zeroOffset += turnRate;

        if (turnRate < min)
            min = turnRate;
        else if (turnRate > max)
            max = turnRate;
        wait1Msec(calInterval);
    } //for loop

    gyro->zeroOffset /= numSamples;
    gyro->deadBand = max - min;
    return;
}   //GyroCal

// This function performs the gyro task where it integrates the turn rate into a heading value.

void GyroTask(GYRO* gyro) {
    long currTime;
    currTime = nPgmTime;
#ifdef HTSMUX_STATUS
    gyro->turnRate = (gyro->gyroFlags & GYROF_HTSMUX) ? HTGYROreadRot((tMUXSensor)gyro->sensorID) : HTGYROreadRot((tSensors)gyro->sensorID);
#else
    gyro->turnRate = HTGYROreadRot((tSensors)gyro->sensorID);
#endif
    gyro->turnRate -= gyro->zeroOffset;
    gyro->turnRate = DEADBAND(gyro->turnRate, gyro->deadBand);
    if (gyro->gyroFlags & GYROF_INVERSE)
        gyro->turnRate = -gyro->turnRate;
    gyro->heading += (float)gyro->turnRate*(currTime - gyro->timestamp)/1000;
    gyro->timestamp = currTime;
    return;
}   //GyroTask

// This function resets the gyro heading.

void GyroReset(GYRO* gyro) {
    GyroTask(gyro);
    gyro->heading = 0;
    return;
}   //GyroReset

// This function initializes the gyro sensor.

void GyroInit(GYRO* gyro, int sensorID, int gyroFlags) {
    gyro->sensorID = sensorID;
    gyro->gyroFlags = gyroFlags & GYROF_USER_MASK;
#ifdef HTSMUX_STATUS
    if (gyro->gyroFlags & GYROF_HTSMUX)
        HTGYROstartCal((tMUXSensor)sensorID);
    else
        HTGYROstartCal((tSensors)sensorID);
#else
    HTGYROstartCal((tSensors)sensorID);
#endif
    GyroCal(gyro, GYRO_NUM_CAL_SAMPLES, GYRO_CAL_INTERVAL);
    gyro->timestamp = nPgmTime;
    GyroReset(gyro);
    return;
}   //GyroInit

static void setGyroTurnTarget(GYRO* gyro, float goal) {
	g_turnTarget = GyroGetHeading(gyro) + goal;
}	//setGyroTurnTarget

void gyroTurn(GYRO* gyro, float turnTarget) {
	setGyroTurnTarget(gyro, turnTarget);
	ClearTimer(T1);
	PID pid;
	pid_zeroize(&pid);
	float error = g_turnTarget - GyroGetHeading(gyro);

	while (abs(error) > g_tolerance) {
		GyroTask(gyro);
		error = g_turnTarget - GyroGetHeading(gyro);
  	pid_update(&pid, error, time1(T1) - prev_time);
		prev_time = time1(T1);
		motor[leftmotor_1] = sgn(motor[leftmotor_1])*pid.control;
		motor[rightmotor_1] = -sgn(motor[rightmotor_1])*pid.control;
		#ifndef setting_twoMotors
		motor[leftmotor_2] = sgn(motor[leftmotor_2])*pid.control;
		motor[rightmotor_2] = -sgn(motor[rightmotor_2])*pid.control;
		#endif
	}

  motor[leftmotor_1] = 0;
  motor[rightmotor_1] = 0;
  motor[leftmotor_2] = 0;
  motor[rightmotor_2] = 0;
}
