// encoders.h
// Header file for encoders.c

// Not yet implemented:
long inchesToTicks(float inches); //shortcut to drive ticks
long inchesToDriveTicks(float inches);
long inchesToStrafeTicks(float inches);

long centimetersToTicks(float centimeters); //shortcut to drive ticks
long centimetersToDriveTicks(float centimeters);
long centimetersToStrafeTicks(float centimeters);

long degreesToTicks(float degrees); //shortcut to turn ticks
long degreesToTurnTicks(float degrees);
long degreesToSwingTicks(float degrees);

long raidansToTicks(float radians); //shortcut to turn ticks
long radiansToTurnTicks(float radians);
long radiansToSwingTicks(float radians);