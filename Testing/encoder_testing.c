#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     grab,					 tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     rightmotor_2,  tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backboard,     tmotorTetrix, openLoop)

#define setting_twoEncoders
#include "../api/api.c"

task main() {
	//resets the encoders
	//if we fail to do this none of the encoder functions will work
  initializeAPI();
  initializeRobot();

  //low level style
  setMovement(100, 0);
  moveFor(inchesToDriveTicks(48));
  //should automatically halt in moveFor();
  //moveFor() also resets the encoders as soon as it stops.

  setMovement(0, 50);
  moveFor(degreesToRotateTicks(180));

  //high level style
  driveInches(48, 100);

  rotateDegrees(180, -50);

  //I think that we should only use the high level functions for swinging.
  swingDegrees(90, 1, 100);
  swingDegrees(90, 1, -100);

  swingDegrees(90, -1, 100);
  swingDegrees(90, -1, -100);

  //should end up exactly where it started
}
