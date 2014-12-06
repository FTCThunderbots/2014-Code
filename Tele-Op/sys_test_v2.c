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

#define setting_twoEncoders
#define pressTime 300

task displayDebugging();
static short nxtFunction = 1;
static string currentDisplay = "";

task main()
{

	nNxtExitClicks = 999999998;

	while (nxtFunction != 0){
		if (nxtFunction == 1){
			currentDisplay = "Left hand drive";
			nxtDisplayCenteredTextLine(0, "Left hand drive");
			if (nNxtButtonPressed == 3){
				nxtFunction++;
				wait1Msec(pressTime);
			}
			while (nNxtButtonPressed == 2){
				motor[leftmotor_1] = -100;
				motor[leftmotor_2] = -100;
			}
				motor[leftmotor_1] = 0;
				motor[leftmotor_2] = 0;
			while (nNxtButtonPressed == 1){
				motor[leftmotor_1] = 100;
				motor[leftmotor_2] = 100;
			}
				motor[leftmotor_1] = 0;
				motor[leftmotor_2] = 0;
			if (nNxtButtonPressed == 0)
				nxtFunction -= nxtFunction;
		}

		if (nxtFunction == 2){
			currentDisplay = "Right hand drive";
			nxtDisplayCenteredTextLine(0, "Right hand drive");
			if (nNxtButtonPressed == 3){
				nxtFunction++;
				wait1Msec(pressTime);
			}
			while (nNxtButtonPressed == 2){
				motor[rightmotor_1] = -100;
				motor[rightmotor_2] = -100;
			}
				motor[rightmotor_1] = 0;
				motor[rightmotor_2] = 0;
			while (nNxtButtonPressed == 1){
				motor[rightmotor_1] = 100;
				motor[rightmotor_2] = 100;
			}
				motor[rightmotor_1] = 0;
				motor[rightmotor_2] = 0;
			if (nNxtButtonPressed == 0)
				nxtFunction = 0;
		}

		if (nxtFunction == 3){
			currentDisplay = "Sweeper";
			nxtDisplayCenteredTextLine(0, "Sweeper");
			if (nNxtButtonPressed == 3){
				nxtFunction++;
				wait1Msec(pressTime);
			}
			while (nNxtButtonPressed == 2)
				motor[sweep] = -100;
			motor[sweep] = 0;
			while (nNxtButtonPressed == 1)
				motor[sweep] = 100;
			motor[sweep] = 0;
			if (nNxtButtonPressed == 0)
				nxtFunction = 0;
		}

		if (nxtFunction == 4){
			currentDisplay = "Conveyor"
			nxtDisplayCenteredTextLine(0, "Conveyor");
			if (nNxtButtonPressed == 3){
				nxtFunction++;
				wait1Msec(pressTime);
			}
			while (nNxtButtonPressed == 2)
				motor[conveyor] = -100;
			motor[conveyor] = 0;
			while (nNxtButtonPressed == 1)
				motor[conveyor] = 100;
			motor[conveyor] = 0;
			if (nNxtButtonPressed == 0)
				nxtFunction = 0;
		}
	}
}

task displayDebugging() {
	while (nxtFunction != 0) {

	}
}
