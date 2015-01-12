// gyro.h
// header file for the gyro driver

#include "..\api\Xander_Drivers\drivers\hitechnic-gyro.h"

// Constants
#define GYROF_USER_MASK         0x00ff
#define GYROF_INVERSE           0x0001
#ifdef HTSMUX_STATUS
  #define GYROF_HTSMUX          0x0080
#endif

#define GYRO_NUM_CAL_SAMPLES    50
#define GYRO_CAL_INTERVAL       10

// Macros
#define DEADBAND(n,t)           ((abs(n) > (t))? (n): 0)
#define GyroGetTurnRate(p)      (p->turnRate)
#define GyroGetHeading(p)       (p->heading)

// the gyro type
typedef struct
{
    int   sensorID;
    int   gyroFlags;
    int   zeroOffset;
    int   deadBand;
    long  timestamp;
    int   turnRate;
    float heading;
} GYRO;

void GyroCal(GYRO* gyro, int numSamples, int calInterval);
void GyroTask(GYRO* gyro);
void GyroReset(GYRO* gyro);
void GyroInit(GYRO* gyro, int sensorID, int gyroFlags);

static void setGyroTurnTarget(GYRO* gyro, float goal);
void gyroTurn(GYRO* gyro, float turnTarget);
