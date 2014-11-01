#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     wheel,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

void setWheelPower(int power){
	motor[wheel] = power;
}

int correctJoystick(int joystick) {
	if (abs(joystick) <= 15) // if joystick is between -15 and +15
		return 0; //completely disregard the input from the joystick
	else
		return joystick; //leave the input unchanged
}

task main()
{
	while (true) {
		 if (nNxtButtonPressed == 3)
		   motor[wheel] = 100;
	}
}
