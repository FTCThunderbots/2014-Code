// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments

#include "api.h"

// Joysticks
const int JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 128; //should only be changed if a different joystick is used

// Movement
const int DRIVE_MIN_POWER = 0; //power cannot be in the open interval (0, min)
const int DRIVE_MAX_POWER = 100; //power cannot exceed max
const int STRAFE_MIN_POWER = 0;
const int STRAFE_MAX_POWER = 100;
const int TURN_MIN_POWER = 0;
const int TURN_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits

// Motor Constants
const int MOTOR_MIN_POWER = 0; //not yet implemented
const int MOTOR_MAX_POWER = 100;