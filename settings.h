// settings.h
// should contain all setting and configuration constants for the robot
// different groups of settings should be separated by comments

// Joysticks
unsigned const short JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
unsigned const short JOYSTICK_MAX_VALUE = 128; //should only be changed if a different joystick is used

// Movement
unsigned const short DRIVE_MIN_POWER = 0; //power cannot be in the open interval (0, min)
unsigned const short DRIVE_MAX_POWER = 100; //power cannot exceed max
unsigned const short STRAFE_MIN_POWER = 0;
unsigned const short STRAFE_MAX_POWER = 100;
unsigned const short TURN_MIN_POWER = 0;
unsigned const short TURN_MAX_POWER = 100;
const double MOVE_POWER_SCALE = 1.0; //used for imposing speed limits

// Motors and Hardware
unsigned const short MOTOR_MIN_POWER = 0; //not yet implemented
unsigned const short MOTOR_MAX_POWER = 100;