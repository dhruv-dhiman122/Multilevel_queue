

#include <stdio.h>
#include <stdlib.h>
#include "process_control_block.h"

//====================== Space for macro ===========================//

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

//======================= space for struct or union ==============================

int sjf_program_counter;

//======================== Sapce for user defined function ==========================/

void Sort(PCB process[], int number) {
  for(int i = 0; i < number; i++) {
    for(int j = 0; j <number-i-1; j++) {
      if(process[j].burst_time > process[j+1].burst_time) {
        float temp = process[j+1].burst_time;
        process[j].burst_time = temp;
        process[j+1].burst_time = process[j].burst_time;
      }
    }
  }
}

void sjfAlgorithm(PCB process[], int n) { 
    int completed = 0;
    float current_time = 0;
    int isCompleted[n];

    for(int i = 0; i < n; i++) {
        isCompleted[i] = 0;
    }

    while(completed < n) {
        int idx = -1;
        float minBurst = 1e9;

        for(int i = 0; i < n; i++) {
            if(process[i].arrival_time <= current_time && !isCompleted[i]) {
                if(process[i].burst_time < minBurst) {
                    minBurst = process[i].burst_time;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            float startTime = (current_time > process[idx].arrival_time) ? current_time : process[idx].arrival_time;
            
            process[idx].completion_time = startTime + process[idx].burst_time;
            process[idx].turnaround_time = process[idx].completion_time - process[idx].arrival_time;
            process[idx].wait_time = process[idx].turnaround_time - process[idx].burst_time;
            current_time = process[idx].completion_time;

            isCompleted[idx] = 1;
            completed++;

            printf("process = %d, Arrival Time = %.2f, Brust time = %.2f, start = %.2f, completion time = %.2f, turn around time = %.2f, waiting time = %.2f\n", process[idx].process_id, process[idx].arrival_time, process[idx].burst_time, startTime, process[idx].completion_time,
                    process[idx].turnaround_time, process[idx].wait_time);
        }
        else {
            current_time++;
        }
    }
}

void display_result(PCB process[], int number) {
	for(int i = 0; i < number; i++) {
		printf("The process %d's  wait time is %.2f\n",i+1, process[i].wait_time);
		printf("The process %d's turn around time is %.2f\n", i+1, process[i].turnaround_time);
	}
}

//============================ Space for only main function =======================//
int main(int argc, char* argv[]) {
  
  if(argc < 2) {
    printf("THERE MUST BE MORE THAN 1 VARIABLE!!");
    exit(EXT_FAILURE);
  }
   
  sjf_program_counter = atoi(argv[1]);
  PCB* process = (PCB*)malloc(sjf_program_counter * sizeof(PCB));
  for(int i = 0; i < sjf_program_counter; i++) {
    printf("Enter the %d process's arrival time\n",i+1);
    scanf("%f",&process[i].arrival_time);
    printf("Enter the %d process's burst time\n",i+1);
    scanf("%f",&process[i].burst_time);
  }
  
  //section for calling the function
  Sort(process, sjf_program_counter);

  sjfAlgorithm(process, sjf_program_counter);

  display_result(process, sjf_program_counter);
  
  free(process);
  exit(EXT_SUCCESS);
}
