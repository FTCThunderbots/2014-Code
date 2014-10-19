// API_Example.c
// Example of how to use the api

#define configfile "config.c"
#define timersused 0
#define rulersused 0
// All of these lines are optional

#include "api.h"
// Must have this line in ALL programs

// You can now use all api methods in your program

/* INSTRUCTIONS FOR DEFINING KEYWORDS:
 *
 * 1. configfile should be a string literal containing the file name of
 * the program's custom config file. To use the default config file,
 * simply don't include this line.
 *
 * 2. timersused should be an integer representing the maximum amount of
 * timer objects that the program will use. There can be more timers requested
 * here than the program actually uses, with very very little wasted memory
 * space
 *
 * 3. rulersused should be the same thing as timersused, but for ruler objects
 * instead of timer objects.
 */
 
 /* HOW TO CREATE A TIMER OBJECT:
  * #define timersused 1
  * Timer_t foo;
  * initTimer(&foo);
  * startTimer(&foo);
  * // after this, the timer will be running
  * // all functions should use the & operator
  * /