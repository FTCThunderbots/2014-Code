// functions.h
// Header file for functions.c

#define FUNCTIONS_INCLUDEGUARD

void initGrabSystem();
void grabGoal();
task grabGoalTask();
void releaseGoal();
task releaseGoalTask();
void toggleGrab();
task toggleGrabTask();

void initBackboardServo();
void engageBackboard();
void disengageBackboard();

void setBackboardServoJoystick();
void setGoalHookJoystick();
void setSweeperJoystick();
void setConveyorJoystick();