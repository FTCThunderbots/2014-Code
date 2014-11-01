// ruler.h
// Header file for ruler.c

#define RULER_INCLUDEGAURD

typedef struct Ruler {
   long left1_startTicks;
   long left2_startTicks;
   long right1_startTicks;
   long right2_startTicks;
   
	long left1_ticks;
   long left2_ticks;
   long right1_ticks;
   long right2_ticks;
   
   long left_ticks;
   long right_ticks;
   long front_ticks;
   long back_ticks;
   
   long drive_ticks;
   long strafe_ticks;
   long rotate_ticks;
   long swing_ticks;
   
   float drive_inches;
   float strafe_inches;
   float rotate_degrees;
   float swing_degrees;
   
   bool initialized;
   bool running;   
} Ruler_t;

typedef Ruler_t * pRuler_t;