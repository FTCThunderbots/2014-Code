/* teleop.c | Common tele-op functioms
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
	if (/*joy2Btn(3) || */joy2Btn(4))
		motor[conveyor] = CONVEYOR_MOTOR_SLOW_SPEED; // 40
	else if (joy2Btn(6) || joy2Btn(2))
		motor[conveyor] = CONVEYOR_MOTOR_SPEED; // 100
	else if (joy2Btn(8))
		motor[conveyor] = -CONVEYOR_MOTOR_SPEED; // -100
	else
		motor[conveyor] = 0;
}
