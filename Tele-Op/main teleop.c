// main teleop.c
// Main tele-op program

#include "api.c"

task main() {
	initializeAPI();
	while (true) {
		getJoystickSettings(joystick);
		setMovement(joystick.joy1_y1, joystick.joy1_x1, joystick.joy1_x2);
		wait1MSec(10);
	}
}