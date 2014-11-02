// encoders.h
// Header file for encoders.c

#define ENCODERS_INCLUDEGAURD

// Accessing encoder values
long getEncoder_left1();
long getEncoder_left2();
long getEncoder_right1();
long getEncoder_right2();

// Setting encoder values
void setEncoder_left1(long val);
void setEncoder_left2(long val);
void setEncoder_right1(long val);
void setEncoder_right2(long val);

// Shortcut methods: useful for iterations(?)
long getEncoder(string enc);
void setEncoder(string enc, long val);

// Unit conversions
long degreesToTicks(float degrees);
long degreesToTurnTicks(float degrees);
long degreesToSwingTicks(float degrees);

long inchesToTicks(float inches);
long inchesToDriveTicks(float inches);
long inchesToStrafeTicks(float inches);

long centimetersToTicks(float centimeters);
long centimetersToDriveTicks(float centimeters);
long centimetersToStrafeTicks(float centimeters);