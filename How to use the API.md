#How to use the api:
-----------------------

##Macros:
Macros are essentially super-global variables that can be 
accessed anywhere in the system while the program is running.
The following lines can be defined in any program.
All of these lines are optional to make the program compile,
but necessary if you want to use certain features of the API.
Put these at the top of the program, directly below the
configurations (#pragma).

```
#define timersused 0
#define rulersrsused 0
#define compass_name compass
#define setting_twoEncoders
#define setting_twoMotors
```

If the first two lines are left out, their value will default to zero.
If your program uses a variable amount of timers, set the amount
used to a high estimate (around ten above how many you expect
to be the most that you need at once), because very little 
extra memory is consumed before the timer or ruler is defined.
The compass_name field should be defined to the name of the compass 
sensor exactly as it appears in the configurations. Use similar 
settings for other sensor types. The definition of setting_twoEncoders 
will tell the API to only look for encoders on the front wheels,
and not throw off other measurements. The definition of setting_twoMotors 
will tell the API that the robot only has two motors dedicated to movement.
If this is defined, setting_twoEncoders will automatically be defined as well.


##Getting all of the api functions:
This line is requried in all programs that use the API. Place it below your
configurations, and below any optional settings that you've defined, but in
front of any other part of your program.

```
#include "../api/api.c"
```

In the task main, run the following line of code before all other code:

```
initializeAPI();
```

Now you may use any of the api methods outside of the api!

##Final code for getting the api:
```
//...
#define timersused 0
#define rulersrsused 0
#define compass_name compass
#define setting_twoEncoders
#define setting_twoMotors

#include "api.c"

//...
task main() {
	initializeAPI();
	//...
}

//...
```

##Using Timers:
The api has a sophisticated timer system written into it. In
order to implement one of the api timers, use the following code
in your task main after setting up the api:

```
Timer_t foo;
initTimer(&foo);
startTimer(&foo);
```
After this, the timer, in this case named foo, will be running
all functions should use the & (address of) operator on your
timer object. If you want to know exactly what this is and what
it does, talk to Daniel, Pranav, or Zach.

Instead of using the & operator all of the time you could also create
a second variable pointing to foo and use that as the arguements. Ex:

```
Timer_t foo;
pTimer_t bar = &foo;
initTimer(bar);
startTimer(bar);
```

The line `pTimer_t bar = &foo;` is equivalent to `Timer_t * bar = &foo;`
if you want to use raw C.
