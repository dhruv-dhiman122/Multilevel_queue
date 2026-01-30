

#include <stdio.h>
#include <stdlib.h>

//====================== Space for macro ===========================//

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

//======================= space for struct or union ==============================

struct Process {
  long long id;
  float burst_time;
  float arrival_time;
  float completion_time;
  float wait_time;
  float turnaround_time;
};

//======================== Sapce for user defined function ==========================/

void Sort(struct Process process[], int number) {
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

void sjfAlgorithm(struct Process process[], int number) {
	int current_time = 0;
	for(int i = 0; i < number; i++) {
		if(current_time < process[i].arrival_time) {
			current_time = process[i].arrival_time;
		}
		process[i].completion_time = current_time + process[i].burst_time;
		process[i].turnaround_time = process[i].completion_time - process[i].arrival_time;
		process[i].wait_time = process[i].turnaround_time - process[i].burst_time;
	}
}

void diplay(struct Process process[], int number) {
	for(int i = 0; i < number; i++) {
		printf("The process %d's  arrival time is %.2f\n",i+1, process[i].arrival_time);
		printf("The process %d's burst time is %.2f\n", i+1, process[i].burst_time);
	}
}

//============================ Space for only main function =======================//
int main(int argc, char* argv[]) {
  
  if(argc < 2) {
    printf("THERE MUST BE MORE THAN 1 VARIABLE!!");
    exit(EXT_FAILURE);
  }
   
  int number = (int)argv[2];
  struct Process* process = (struct Process*)malloc(number * sizeof(struct Process));
  for(int i = 0; i < number; i++) {
    printf("Enter the %d process's arrival time\n",i+1);
    scanf("%f",&process[i].arrival_time);
    printf("Enter the %d process's burst time\n",i+1);
    scanf("%f",&process[i].burst_time);
  }

  free(process);
  exit(EXT_SUCCESS);
}
