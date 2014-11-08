// timer debug stream test

#define DEBUG_STREAM_ON

string label1 = "Total Runtime:"
#define debugStreamLine1 label1
#define debugStreamType1 "%s"

#define debugStreamLine2 runtime()
#define debugStreamType2 "%.2f"

#define debugStreamLine3 timeInMS()
#define debugStreamType3 "%l"

string label2 = "Debug Variables"
#define debugStreamLine4 label2
#define debugStreamType4 "%s"

#define debugStreamLine5 currentTime
#define debugStreamType5 "%l"

#define debugStreamLine6 minutesPassed
#define debugStreamType6 "%b"

#define debugStreamLine7 timers
#define debugStreamType7 "%b"

#define debugStreamLine8 (float)time1000[T1]
#define debugStreamType8 "%f"

#include "../api/api.c"

task main() {
   while(true) {/*nothing*/}
}