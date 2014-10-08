// settings.h
// should contain all setting and configuration constants for the robot
// different groups of settings should be separated by comments
#include config.h

// Joysticks
const ubyte JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
const ubyte JOYSTICK_MAX_VALUE = 128; //should only be changed if a different joystick is used

// Movement
const ubyte DRIVE_MIN_POWER = 0; //power cannot be in the open interval (0, min)
const ubyte DRIVE_MAX_POWER = 100; //power cannot exceed max
const ubyte STRAFE_MIN_POWER = 0;
const ubyte STRAFE_MAX_POWER = 100;
const ubyte TURN_MIN_POWER = 0;
const ubyte TURN_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits

// Motors and Hardware
const ubyte MOTOR_MIN_POWER = 0; //not yet implemented
const ubyte MOTOR_MAX_POWER = 100;