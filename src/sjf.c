

#include <stdio.h>
#include <stdlib.h>

//====================== Space for macro ===========================//

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

//======================== Sapce for user defined function ==========================/


//========================= Space for struct ===============================//

struct Process {
  long long id;
  float burst_time;
  float arrival_time;
  float completion_time;
  float wait_time;
  float turnaround_time;
};

//============================ Space for only main function =======================//
int main(int argc, char* argv[]) {


  exit(EXT_SUCCESS);
}
