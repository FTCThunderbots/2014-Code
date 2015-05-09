#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          grab,          tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)

/* main_teleop_v1.c | Major version 1 of the robot's tele-op code **SUPERCEDED**
 * Copyright (C) 2015 Thunderbots-5604
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#define setting_noEncoders

#include "../api/api.c"

void setSweep();
void setConvey();
void setBackboard();

task main() {
	initializeAPI();
	initializeRobot();
	while (true) {
		getJoystickSettings(joystick);
		setMovementFromJoystick(joystick.joy1_y1, joystick.joy1_x2);
		setSweep();
		setConvey();
	}
}

void setSweep() {
	if (joy2Btn(1) || joy2Btn(4))
		motor[sweep] = SWEEP_MOTOR_SLOW_SPEED;
	else if (joy2Btn(5) || joy2Btn(2))
		motor[sweep] = SWEEP_MOTOR_SPEED;
	else if (joy2Btn(7))
		motor[sweep] = -SWEEP_MOTOR_SPEED;
	else
		motor[sweep]= 0;
}

void setConvey() {
	if (joy2Btn(3) || joy2Btn(4))
		motor[conveyor] = CONVEYOR_MOTOR_SLOW_SPEED;
	else if (joy2Btn(6) || joy2Btn(2))
		motor[conveyor] = CONVEYOR_MOTOR_SPEED;
	else if (joy2Btn(8))
		motor[conveyor] = -CONVEYOR_MOTOR_SPEED;
	else
		motor[conveyor] = 0;
}

void setBackboard() {
	if (joy1Btn(1))
		disengageBackboard();
	if (joy1Btn(3))
		engageBackboard();
}
