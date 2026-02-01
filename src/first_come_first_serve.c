/*
 * This file is the implemtation for first come first server
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "process_control_block.h"

//==================== Space for user made variable ======================

int fcfs_program_counter;
//==================== Space for macro ===========================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1


//==================== Space for user made function ===================

void Sort(PCB process[], int number) {
  for(int i = 0; i < number; i++) {
    for(int j = 0; j < number - i -1; j++) {
      if(process[j].arrival_time < process[j+1].arrival_time) {
        float temp = process[j+1].arrival_time;
        process[j+1].arrival_time = process[i].arrival_time;
        process[j].arrival_time = temp;
      }
    }
  }
}

void fcfsAlgorithm(PCB process[], int number) {
  int current = 0;
  for(int i = 0; i < number; i++) {
    if(current < process[i].arrival_time) {
      current = process[i].arrival_time;
    }
      process[i].completion_time = current + process[i].burst_time;
      process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
      process[i].wait_time = process[i].turnaround_time - process[i].burst_time;
      update_process_counter(&process[i], fcfs_program_counter);
      fcfs_program_counter++;
      current = process[i].completion_time;
  }
}

void display(PCB process[], int number) {
  for(int i = 0; i < number; i++) {
    printf("The wait time for the process %d is %.2f\n", i+1, process[i].wait_time);
    printf("The turnaround time for process %d is %.2f\n",i+1, process[i].turnaround_time);
  }
}

//==================== Space for main function ========================
int main(int argc, char* argv[]) {
  
  if(argv < 2) { // if there was a less number for making the process
    fprintf(stderr, "There must be at a number give for making the process\n");
    exit(EXT_FAILURE);
  }
  fcfs_program_counter = atoi(argv[1]);
  PCB* process = (PCB*)malloc(fcfs_program_counter*sizeof(PCB));
  //asking for the details
  float temp_Arrival, temp_Burst;
  for(int i = 0; i < fcfs_program_counter; i++) {
    printf("Enter the process %d arrival time",i+1);
    scanf("%f",&temp_Arrival);
    process[i].arrival_time = temp_Arrival;
    printf("Enter the process %d burst time",i+1);
    scanf("%f",&temp_Burst);
    process[i].burst_time = temp_Burst;
    create_process(process[i].process_id, 0, process[i].arrival_time, process[i].burst_time);
  }
  //section for calling the function
  Sort(process, fcfs_program_counter);

  fcfsAlgorithm(process, fcfs_program_counter);
  
  display(process, fcfs_program_counter);
  free(process);
  process = NULL;
  exit(EXT_SUCCESS);
}
