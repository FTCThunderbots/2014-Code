// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments

#define SETTINGS_INCLUDEGAURD

// Joysticks
const int JOYSTICK_MIN_VALUE = 10; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 127; //should only be changed if a different joystick is used

// Movement
const byte DRIVE_MIN_POWER = 0; //abs(power) cannot be in the open interval (0, min)
const byte DRIVE_MAX_POWER = 100; //abs(power) cannot exceed max
const byte STRAFE_MIN_POWER = 0;
const byte STRAFE_MAX_POWER = 100;
const byte TURN_MIN_POWER = 0;
const byte TURN_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits
const float DRIVE_POWER_WEIGHT = 1.0; //weights are used for changing responsiveness of different movements
const float STRAFE_POWER_WEIGHT = 1.0;
const float TURN_POWER_WEIGHT = 1.0;

// Motor Constants
const byte MOTOR_MIN_POWER = 0; //not yet implemented
const byte MOTOR_MAX_POWER = 100;
const byte DEFAULT_MOTOR_POWER = 100; // when power is not specified

// Encoder Settings
const int ENCODER_TICKS_PER_ROTATION = 1440; // May not be correct, requires testing.
const int ENCODER_TICKS_PER_DRIVE_INCH = 0; // here we might be able to do some math, but will still require precise calibration
const int ENCODER_TICKS_PER_STRAFE_INCH = 0; // guess and check
const int ENCODER_TICKS_PER_TURN_DEGREE = 0; // for rotating in place. just guess and check
const int ENCODER_TICKS_PER_SWING_DEGREE = 0; // should be about double the turn degrees, but guess and check.
#warn "(settings.c) Encoder values still need to be set! Encoder functions will not work."

int delete_this_function_when_encoder_values_are_referenced_somewhere_else() {
	// this_is_just_so_it_doesnt_throw_unrefrenced_warnings
	return ENCODER_TICKS_PER_ROTATION + ENCODER_TICKS_PER_DRIVE_INCH
		+ ENCODER_TICKS_PER_STRAFE_INCH + ENCODER_TICKS_PER_TURN_DEGREE + ENCODER_TICKS_PER_SWING_DEGREE;
}
