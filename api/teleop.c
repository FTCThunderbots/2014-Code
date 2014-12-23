// teleop.c
// All of the teleop functions

#include "teleop.h"

void setBackboardJoystick() {
	if (joy2Btn(1))
		motor[backboard] = BACKBOARD_MOTOR_SPEED;
	else if (joy2Btn(3))
		motor[backboard] = -BACKBOARD_MOTOR_SPEED;
	else
		motor[backboard] = 0;
}

void setGoalHookJoystick() {
	if (joy1Btn(2))
		motor[grab] = GRAB_MOTOR_SPEED;
	else if (joy1Btn(4))
		motor[grab] = -GRAB_MOTOR_SPEED;
	else
		motor[grab] = 0;
}

void setSweeperJoystick() {
	if (joy2Btn(1))
		motor[sweep] = SWEEP_MOTOR_SLOW_SPEED; // 40
	else if (joy2Btn(4))
		motor[sweep] = -SWEEP_MOTOR_SLOW_SPEED;
	else if (joy2Btn(5) || joy2Btn(2))
		motor[sweep] = -SWEEP_MOTOR_SPEED; // 100
	else if (joy2Btn(7))
  		motor[sweep] = SWEEP_MOTOR_SPEED; // -100
	else
		motor[sweep]= 0;
}

void setConveyorJoystick() {
	if (joy2Btn(3) || joy2Btn(4))
		motor[conveyor] = CONVEYOR_MOTOR_SLOW_SPEED; // 40
	else if (joy2Btn(6) || joy2Btn(2))
		motor[conveyor] = CONVEYOR_MOTOR_SPEED; // 100
	else if (joy2Btn(8))
		motor[conveyor] = -CONVEYOR_MOTOR_SPEED; // -100
	else
		motor[conveyor] = 0;
}
