#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          grab,          tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)

#define setting_noEncoders

#include "../api/api.c"

void setGoalHook();
void setBackboardServo();
void setSweeper();
void setConveyor();
void displayDebugInfo();

static const bool DISPLAY_DEBUG_INFORMATION = true;

task main()
{
	initializeAPI();
	initializeRobot();
	while (true) {
		getJoystickSettings(joystick);
		//setMovementFromJoystickComposite(joystick.joy1_y1, joystick.joy1_x2);
		setMovement(correctJoystickComposite(joystick.joy1_y1), correctJoystickComposite(joystick.joy1_x2));
		setGoalHook();
		setBackboardServo();
		setSweeper();
		setConveyor();
		displayDebugInfo();
	}
}

void setBackboardServo() {
	if (joy1Btn(1))
		disengageBackboard(); // set to base
	if (joy1Btn(3))
		engageBackboard(); // set to target
}

void setGoalHook() {
	if (joy1Btn(2))
		grabGoal();
	if (joy1Btn(4))
		releaseGoal();
}

void setSweeper() {
	if (joy2Btn(1) || joy2Btn(4))
		motor[sweep] = SWEEP_MOTOR_SLOW_SPEED; // 40
	else if (joy2Btn(5) || joy2Btn(2))
		motor[sweep] = SWEEP_MOTOR_SPEED; // 100
	else if (joy2Btn(7))
  	motor[sweep] = -SWEEP_MOTOR_SPEED; // -100
	else
		motor[sweep]= 0;
}

void setConveyor() {
	if (joy2Btn(3) || joy2Btn(4))
    motor[conveyor] = CONVEYOR_MOTOR_SLOW_SPEED; // 40
  else if (joy2Btn(6) || joy2Btn(2))
    motor[conveyor] = CONVEYOR_MOTOR_SPEED; // 100
  else if (joy2Btn(8))
    motor[conveyor] = -CONVEYOR_MOTOR_SPEED; // -100
  else
    motor[conveyor] = 0;
}

void displayDebugInfo() {
	if (DISPLAY_DEBUG_INFORMATION) {
		//nxtDisplayCenteredTextLine(5, "GRAB: %d", nMotorEncoder[grab]);
		//nxtDisplayCenteredTextLine(6, "BACKBOARD: %d", servo[backboard]);
		//nxtDisplayCenteredTextLine(0, "sweep: %d", motor[sweep]);
		nxtDisplayCenteredTextLine(1, "left1: %d", motor[leftmotor_1]);
		nxtDisplayCenteredTextLine(2, "left2: %d", motor[leftmotor_2]);
		nxtDisplayCenteredTextLine(3, "r1: %d", motor[rightmotor_1]);
		nxtDisplayCenteredTextLine(4, "r2: %d", motor[rightmotor_2]);
	}
}
