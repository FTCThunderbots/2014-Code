/* settings.c | Common timing and power contstants
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

#define SETTINGS_INCLUDEGUARD

//#warn "(settings.c) Please set time and encoder vals for auto grabbing and auto backboard"

// Functional motor constants
const byte GRAB_MOTOR_SPEED = 35;
const int GRAB_MOTOR_UP_TIME = 300;
const int GRAB_MOTOR_DOWN_TIME = 325;
const int GRAB_MOTOR_DOWN_POS = 100;
const int GRAB_MOTOR_UP_POS = 1;
#define grab_is_motor_enc //TODO: implement this!

const byte BACKBOARD_MOTOR_SPEED = 30;
const int BACKBOARD_MOTOR_DOWN_TIME = 500;
const int BACKBOARD_MOTOR_UP_TIME = 565;
const int BACKBOARD_MOTOR_UP_POS = 1; //when we get an encoder on this this is the base pos
const int BACKBOARD_MOTOR_DOWN_POS = 480; //120 degrees
#define backboard_is_motor_enc //TODO: implement this!

const byte SWEEP_MOTOR_SPEED = 100;
const byte SWEEP_MOTOR_SLOW_SPEED = 40; // speed in 'slow' mode

const byte CONVEYOR_MOTOR_SPEED = 100;
const byte CONVEYOR_MOTOR_SLOW_SPEED = 40;

// Encoder Settings
const float ENCODER_TICKS_PER_DRIVE_INCH = 72.0;
const float ENCODER_TICKS_PER_ROTATE_DEGREE = 11.667; // degrees the entire robot rotates
const float ENCODER_TICKS_PER_SWING_DEGREE = 21.9; // degrees the entire robot rotates
const float ENCODER_TICKS_PER_DEGREE = 4.0; //should be exact (1440/360)

//PID Constants
//DO NOT CHANGE UNLESS YOU KNOW WHAT YOU ARE DOING!!!
#define INTEGRAL_CAP 10
#define Kp 0.2
#define Ki 0.01
#define Kd 1

// Turn constant
const byte TURN_CONSTANT = 0; //used for correcting any natural curvature of the robot while driving

// Movement
const byte DRIVE_MIN_POWER = 20; //abs(power) cannot be in (0, min)
const byte DRIVE_MAX_POWER = 100; //abs(power) <= max
const byte ROTATE_MIN_POWER = 20;
const byte ROTATE_MAX_POWER = 100;
const byte STRAFE_MIN_POWER = 0;
const byte STRAFE_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits
const float DRIVE_POWER_WEIGHT = 1.0; //weights are used for changing responsiveness of different movements
const float ROTATE_POWER_WEIGHT = 1.0;
const float STRAFE_POWER_WEIGHT = 1.0;

// Motor Constants
const byte MOTOR_MIN_POWER = 5; // don't burn out the motor by giving it too low a power that it can't move
const byte MOTOR_MAX_POWER = 100; // conserve power? a global speed limit?
const byte DEFAULT_MOVE_POWER = 100; // the power when power is not specified

// Joysticks
const int JOYSTICK_MIN_VALUE = 5; //abs(joystick) cannot be in (0, min)
const int JOYSTICK_MAX_VALUE = 127; //abs(joystick) <= max
const float JOYSTICK_LINEAR_WEIGHT = 2.5; // weight of the linear scale to the exponential scale

bool usePID = false;
