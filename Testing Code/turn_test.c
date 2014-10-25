#pragma config(Sensor, S1,     Infrared,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S2,     Compass,        sensorI2CHiTechnicCompass)

#include "api.h"

void initializeRobot();
void rotateDeg(int degs, byte power);
void correctDegs(int degs);
task main(void)
{
	//objective: test the rotateDeg function
	initializeRobot();

	rotateDeg(90);
	wait1Msec(2000);
	rotateDeg(720);
	wait1Msec(2000);
	rotateDeg(-720);
	wait1Msec(2000);
	rotateDeg(-90);
}

void initializeRobot(){
	resetEncoders();
	brake();
	motor[Lift1] = 0;
	motor[Lift2] = 0;
	motor[Sweep] = 0;
	motor[Flag] = 0;
	servo[bucket] = 102;
}

int correctDegs(int degs) {
	int fullspins = degs/360;
	return degs-(360*fullspins)
}

void rotateDeg(int degs, byte power){
	#warn "Compass sensor is used in rotateDeg"
	//uses compass sensor
	int startFacing = SensorValue[compass];
	setMovement(0, 0, power);
	while(SensorValue[compass] != correctDegs(startFacing+degs)){}
	halt();
}
