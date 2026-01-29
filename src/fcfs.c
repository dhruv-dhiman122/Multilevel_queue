/*
 * This file is the implemtation for first come first server
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//==================== Space for user made variable ======================

struct Process {
  long long pid;
  float arrival_time;
  float burst_time;
  float turnaround_time;
  float wait_time;
};

//==================== Space for macro ===========================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1


//==================== Space for user made function ===================


//==================== Space for main function ========================
int main(int argc, char* argv[]) {
  
  if(argv < 2) { // if there was a less number for making the process
    fprintf(stderr, "There must be at a number give for making the process\n");
    exit(EXT_FAILURE);
  }
  int number = atoi(argv[1]);
  struct Process* process = (struct Process*)malloc(number*sizeof(struct Process));
  //asking for the details
  float temp_Arrival, temp_Burst;
  for(int i = 0; i < number; i++) {
    printf("Enter the process %d arrival time",i+1);
    scanf("%f",&temp_Arrival);
    process[i].arrival_time = temp_Arrival;
    printf("Enter the process %d burst time",i+1);
    scanf("%f",&temp_Burst);
    process[i].burst_time = temp_Burst;
  }

  
  free(process);
  process = NULL;
  exit(EXT_SUCCESS);
}
