// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments

#include "api.h"

// Joysticks
register const int JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
register const int JOYSTICK_MAX_VALUE = 128; //should only be changed if a different joystick is used

// Movement
register const byte DRIVE_MIN_POWER = 0; //power cannot be in the open interval (0, min)
register const byte DRIVE_MAX_POWER = 100; //power cannot exceed max
register const byte STRAFE_MIN_POWER = 0;
register const byte STRAFE_MAX_POWER = 100;
register const byte TURN_MIN_POWER = 0;
register const byte TURN_MAX_POWER = 100;
register const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits

// Motor Constants
register const byte MOTOR_MIN_POWER = 0; //not yet implemented
register const byte MOTOR_MAX_POWER = 100;

//Todo: wheel diameter and tick counts
//
