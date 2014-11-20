// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments

#define SETTINGS_INCLUDEGAURD

// Joysticks
#define JOYSTICK_MIN_VALUE 10 //min value where the reading is accepted as an input
#define JOYSTICK_MAX_VALUE 127; //should only be changed if a different joystick is used

// Movement
#define DRIVE_MIN_POWER 0; //abs(power) cannot be in the open interval (0, min)
#define DRIVE_MAX_POWER 100; //abs(power) cannot exceed max
#define STRAFE_MIN_POWER 0;
#define STRAFE_MAX_POWER 100;
#define ROTATE_MIN_POWER 0;
#define ROTATE_MAX_POWER 100;
#define MOVE_POWER_SCALE 1.0; //used for imposing speed limits
#define DRIVE_POWER_WEIGHT 1.0; //weights are used for changing responsiveness of different movements
#define STRAFE_POWER_WEIGHT 1.0;
#define ROTATE_POWER_WEIGHT 1.0;

// Motor Constants
#define MOTOR_MIN_POWER 0; //not yet implemented
#define MOTOR_MAX_POWER 100;
#define DEFAULT_MOTOR_POWER 100; // when power is not specified

// Encoder Settings
#define TICKS_PER_ROTATION 1440; //requires testing.
#define WHEEL_DIAMETER 3
#define ENCODER_TICKS_PER_DRIVE_INCH TICKS_PER_ROTATION/(WHEEL_DIAMETER*PI); // here we might be able to do some math, but will still require precise calibration
#define ENCODER_TICKS_PER_STRAFE_INCH 100; // guess and check
#define ENCODER_TICKS_PER_ROTATE_DEGREE 100; // for rotating in place. just guess and check
#define ENCODER_TICKS_PER_SWING_DEGREE 200; // should be about double the turn degrees, but guess and check.
#warn "(settings.c) Encoder values still need to be calibrated! Encoder functions will not work."
