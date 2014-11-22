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
task main()
{

	short nxtFunction = 1;
	nNxtExitClicks = 999999999;

	while (nxtFunction != 0){
		if (nxtFunction == 1){
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
				nxtFunction = 0;
		}

		if (nxtFunction == 2){
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

		if (nxtFunction == 5){
			nxtDisplayCenteredTextLine(0, "Grab");
			nxtDisplayCenteredTextLine(1, "%d", nMotorEncoder[grab]);
			if (nNxtButtonPressed == 3){
				nxtFunction = 1;
				wait1Msec(pressTime);
			}
				while (nNxtButtonPressed == 2){
					motor[grab] = -30;
				}
				motor[grab] = 0;

			while (nNxtButtonPressed == 1){
				motor[grab] = 30;
			}
			motor[grab] = 0;
			if (nNxtButtonPressed == 0)
				nxtFunction = 0;
	}

		/*
		if (nxtFunction == 6){
			nxtDisplayCenteredTextLine(0, "Bucket");
			if (nNxtButtonPressed == 3){
				nxtFunction++;
				wait1Msec(pressTime);
			}
			if (nNxtButtonPressed == 2)
				servo[bucket] = 102-50;
			if (nNxtButtonPressed == 1)
				servo[bucket] = 102+50;
			if (nNxtButtonPressed == 0)
				servo[bucket] = 102;
		}

		if (nxtFunction == 7){
			nxtDisplayCenteredTextLine(0, "Pin");
			if (nNxtButtonPressed == 3){
				nxtFunction = 1;
				wait1Msec(pressTime);
			}
			if (nNxtButtonPressed == 2)
				servo[pin] = 30;
			if (nNxtButtonPressed == 1)
				servo[pin] = 0;
			if (nNxtButtonPressed == 0)
				nxtFunction = 0;
		*/
		}
	}
