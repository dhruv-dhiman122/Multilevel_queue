/*
 * The file is for implementing the process library
 * */

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

//======================= Space for macro ============================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

//========================= Space for struct or class =======================

class Process {
  public:
    static programCounter = 0;

    long long pid;
    float arrival_time;
    float burst_time;
    float turnaround_time;
    float wait_time;

    Process(float UserArrival_time, float UserBurst_time) : arrival_time(UserArrival_time), burst_time(UserBurst_time) {}

    inline void MakeProcess(float Arrival_time, float Burst_time) { // the function is for adding the Process
      
    }
}
