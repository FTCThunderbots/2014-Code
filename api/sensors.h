// sensors.h
// Header file for sensors.c

#define SENSORS_INCLUDEGUARD

#ifdef compass_name
#define getCompassValue() SensorValue[compass_name]
#else
#define getCompassValue() -1
#endif