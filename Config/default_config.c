#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)

#define setting_twoEncoders

/* How to set up the robot based on this configurations:


                        FRONT

(mtr_S1_C1_1) |  |-----------------|  | (mtr_S1_C2_1)
leftmotor_1   |--|                 |--|  rightmotor_1
encoder here  |  |                 |  |  encoder here
                 |                 |
                 |                 |
                 |***           ***|
  mtr_s1_c1 -->  |***           ***|  <-- mtr_s1_c2
                 |                 |
                 |                 |
(mtr_S1_C1_2) |  |                 |  | (mtr_S1_C2_2)
leftmotor_2   |--|                 |--|  rightmotor_2
              |  |-----------------|  |

                        BACK

*/
