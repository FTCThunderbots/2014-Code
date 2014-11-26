// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments

#define SETTINGS_INCLUDEGUARD

// Joysticks
const int JOYSTICK_MIN_VALUE = 5; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 127; //should only be changed if a different joystick is used
const byte JOYSTICK_EXPONENTIAL_SCALE = 70;

// Movement
const byte DRIVE_MIN_POWER = 0; //abs(power) cannot be in the open interval (0, min)
const byte DRIVE_MAX_POWER = 100; //abs(power) cannot exceed max
const byte STRAFE_MIN_POWER = 0;
const byte STRAFE_MAX_POWER = 100;
const byte ROTATE_MIN_POWER = 0;
const byte ROTATE_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits
const float DRIVE_POWER_WEIGHT = 1.0; //weights are used for changing responsiveness of different movements
const float STRAFE_POWER_WEIGHT = 1.0;
const float ROTATE_POWER_WEIGHT = 1.0;

// Motor Constants
const byte MOTOR_MIN_POWER = 0; //not yet implemented
const byte MOTOR_MAX_POWER = 100;
const byte DEFAULT_MOTOR_POWER = 100; // when power is not specified

// Encoder Settings
const int ENCODER_TICKS_PER_DRIVE_INCH = 1440/(3*PI); // here we might be able to do some math, but will still require precise calibration
const int ENCODER_TICKS_PER_STRAFE_INCH = 100; // guess and check
const int ENCODER_TICKS_PER_ROTATE_DEGREE = 100; // for rotating in place. just guess and check
const int ENCODER_TICKS_PER_SWING_DEGREE = 200; // should be about double the turn degrees, but guess and check.
#warn "(settings.c) Encoder values still need to be set! Encoder functions will not work."

// Turn constant
const byte TURN_CONSTANT = 0; //used for correcting any natural curvature of the robot while driving

// Functional motor constants
const byte GRAB_MOTOR_SPEED = 50; // speed of the goal-grabbing motor
const int GRAB_MOTOR_OPEN_POS = 0; // encoder position when the goal is not grabbed
const int GRAB_MOTOR_CLOSED_POS = 110; // encoder position when the goal is grabbed
const byte SWEEP_MOTOR_SPEED = 100; // default sweeper motor speed
const byte SWEEP_MOTOR_SLOW_SPEED = 35; // 'slower' sweeper motor speed
const byte CONVEYOR_MOTOR_SPEED = 100; // default conveyor motor speed
const byte CONVEYOR_MOTOR_SLOW_SPEED = 35; // 'slower' conveyor motor speed

// Servo constants
const int BACKBOARD_SERVO_BASE = 128;
const int BACKBOARD_SERVO_TARGET = 250;