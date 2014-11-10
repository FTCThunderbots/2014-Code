// sensors.h
// Header file for sensors.c

#define SENSORS_INCLUDEGAURD

#ifdef compass_name
#define getCompassValue() SensorValue[compass_name]
#else
#define getCompassValue() 0
#endif