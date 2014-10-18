#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     frontLeft,        tmotorTetrix, openLoop)
#pragma config(Motor,	 mtr_S1_C1_2,			backLeft,					tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,			frontRight,				tmotorTetrix,	openLoop)
#pragma config(Motor,	 mtr_S1_C2_2,			backRight,				tmotorTetrix,	openLoop)

#include "JoystickDriver.c"

void setWheelPower(int cheeseburger){
	motor[frontLeft] = cheeseburger;
	motor[frontRight] = cheeseburger;
	motor[backLeft] = cheeseburger;
	motor[backRight] = cheeseburger;
	//int i = 2;
}

task main()
{
	setWheelPower(0);
	waitForStart();
	setWheelPower(100);
	wait10Msec(750);
}
