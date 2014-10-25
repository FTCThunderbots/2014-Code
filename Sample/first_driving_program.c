#pragma config(Motor,  mtr_S1_C1_1,     left,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     left,        tmotorTetrix, openLoop)

static float MOVE_POWER_SCALE = 1;
static byte MOTOR_MAX_POWER;
byte scaleTo(byte value, byte *range, byte *scale);
byte max(byte a, byte b);
//byte absmax(byte *a, byte len);
void setMovement(byte forward, byte right, byte clockwise);
void setMovement(byte forward, byte clockwise);
float max(float *a, byte len);

task main()
{
	motor[left] = 100;
	while(true) {
		getJoystickSettings(joystick);
		setMovement(joystick.joy1_y1, joystick.joy1_x2);
	}
}

byte scaleTo(byte value, byte *range, byte *scale) {
	if (abs(value) < *range)
		return 0;
	if (abs(value) > *(range+1))
		return *(scale+1);
	float posInR = (float)(value - *range) / *(range+2); //should be a percent
	return (byte)(*scale) + (posInR * *(range+2));
}

byte max(byte a, byte b) {
	return a >= b ? a : b;
}

float absmax(float *a, byte len) {
	float cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(abs(cummax), abs(*(a+i)));
	return cummax;
}

void setMovement(byte forward, byte right, byte clockwise) {
   // In RobotC, make these arrays static/global and maybe const
	byte JOYRANGE[3] = {15, 127, 114};
	byte DRVRANGE[3] = {0, 100, 100};
	byte STFRANGE[3] = {0, 100, 100};
	byte TRNRANGE[3] = {0, 100, 100};
	// Array format: min, max, difference

	// First, scale all vectors using values found in settings.c
	forward = scaleTo(forward, &JOYRANGE[0], &DRVRANGE[0]);
	right = scaleTo(right, &JOYRANGE[0], &STFRANGE[0]);
	clockwise = scaleTo(clockwise, &JOYRANGE[0], &TRNRANGE[0]);

	// Next, assign wheel powers using the mecanum algorithm
	float frontLeft = (-forward - right - clockwise)/3;
	float frontRight = (forward - right - clockwise)/3;
	float backLeft = (-forward + right - clockwise)/3;
	float backRight = (forward + right - clockwise)/3;
	//add note about why/how this works in engineering notebook

	float power[4] = {frontLeft, frontRight, backLeft, backRight};

	// find max of all wheel powers
	float max = absmax(&power[0], 4);

	// scale all wheels to fit within motor_max
	if (max > MOTOR_MAX_POWER) {
		float scale = (float)max / MOTOR_MAX_POWER;
		for (int i = 0; i < 4; i++)
			power[i] /= scale;
	}

	for(int i = 0; i < 4; i++)
		power[i] *= MOVE_POWER_SCALE;

	//motor[fl] = frontLeft;
	//motor[fr] = frontRight;
	//motor[bl] = backLeft;
	//motor[br] = backRight;
}

//for tank drive
void setMovement(byte forward, byte clockwise) {
	setMovement(forward, 0, clockwise);
}

float max(float *a, byte len) {
	float cummax = *a;
	for (int i = 1; i < len; i++)
		cummax = max(cummax, *(a+i));
	return cummax;
}
