// encoders.h
// Header file for encoders.c

//Macro Functions for length to ticks
#define IN_TO_TICKS(inches)

long degreesToTicks(float degrees);
long degreesToTurnTicks(float degrees);
long degreesToSwingTicks(float degrees);

long inchesToTicks(float inches);
long inchesToDriveTicks(float inches);
long inchesToStrafeTicks(float inches);

long centimetersToTicks(float centimeters);
long centimetersToDriveTicks(float centimeters);
long centimetersToStrafeTicks(float centimeters);