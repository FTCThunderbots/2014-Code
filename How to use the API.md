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
#define setting_twoEncoders
#define setting_twoMotors
```

The definition of setting_twoEncoders will tell the API to only look for
encoders on the first wheels, and not throw off other measurements. The
definition of setting_twoMotors will tell the API that the robot only has
two motors dedicated to movement. If this is defined, setting_twoEncoders
will automatically be defined as well.

###Sensors:
Sensors are set through macros that are used in api/sensors.c.
The code is written for use with a sensor MUX, and Xander's
drivers are being used. Use this as an example of how to define sensors.
```
#define gyroSensor	msensor_S4_1
#define sonarSensor	msensor_S4_2
#define lightSensor	msensor_S4_3
#define touchSensor	msensor_S4_4
```
The pragma must also contain the following line for all sensors to work:
```
#pragma config(Sensor, S4,     HTSMUX,               sensorI2CCustom)
```

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

You will also need to call initializeRobot() if writing autonomous code.

Now you may use any of the api methods outside of the api!

##Final code for getting the api:
```
//...
#pragma config(Sensor, S4,     HTSMUX,               sensorI2CCustom)

#define setting_twoEncoders
#define setting_twoMotors

#define gyroSensor              msensor_S4_1
#define sonarSensor             msensor_S4_2
#define lightSensor		msensor_S4_3
#define touchSensor             msensor_S4_4

#include "api.c"

//...
task main() {
	initializeAPI();
	//initializeRobot();
	//...
}

//...
```
