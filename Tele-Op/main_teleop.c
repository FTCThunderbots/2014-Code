#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)

// main teleop.c
// Main tele-op program

#include "../api/api.c"

task main() {
	initializeAPI();
	while (true) {
		getJoystickSettings(joystick);
		setMovement(joystick.joy1_y1, joystick.joy1_x1, joystick.joy1_x2);
		wait1Msec(10);
	}
}
