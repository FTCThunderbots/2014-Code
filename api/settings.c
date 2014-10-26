// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments

#define SETTINGS_INCLUDEGAURD

// Joysticks
const int JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 127; //should only be changed if a different joystick is used

// Movement
const byte DRIVE_MIN_POWER = 0; //power cannot be in the open interval (0, min)
const byte DRIVE_MAX_POWER = 100; //power cannot exceed max
const byte STRAFE_MIN_POWER = 0;
const byte STRAFE_MAX_POWER = 100;
const byte TURN_MIN_POWER = 0;
const byte TURN_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits

// Motor Constants
const byte MOTOR_MIN_POWER = 0; //not yet implemented
const byte MOTOR_MAX_POWER = 100;

// Todo: wheel diameter and tick counts
// THAT MEANS PUT IT HERE, NOT IN CONFIG
const int WHEEL_DIAMETER = 0;
#warn "(settings.c) Remove wheel diameter value and redo with ticks. Much more accurate, especially with mecanum."
