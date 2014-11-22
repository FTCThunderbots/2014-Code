#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     infrared,        sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightmotor_1,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     leftmotor_2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     rightmotor_2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     lift1,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     lift2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    bucket,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    pin,                  tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)

/*#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
*/

#define setting_twoEncoders

#include "../api/api.c"

// This program will drive off the ramp, pick up a goal, and carry it to the parking zone
task getEncoders();

task main() {
   initializeAPI();
   waitForStart();
   StartTask(getEncoders);
   /*driveInchesBW(12*10); // 10 feet = 12*10 inches
   rotateDegreesCW(180); // could equally be -180*/
   /*** Pick up the goal right here ***/

   /*driveInchesFW(12*4); //just guessing here
   rotateDegreesCW(30);
   driveInchesFW(12*4); //still guessing*/
   driveInchesFW(12*4);
}

task getEncoders() {
   Ruler_t r;
   initRuler(&r);
   while(true) {
   		nxtDisplayBigTextLine(0, "%d", (int)getDriveTicks(&r));
   }

}
