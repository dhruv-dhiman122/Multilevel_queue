#ifndef PROCESS_CONTROL_BLOCK_H
#define PROCESS_CONTROL_BLOCK_H

typedef struct {
	int process_id;
	int program_counter;
	int priority;
	float arrival_time;
	float burst_time;
	float completion_time;
	float wait_time;
	float turnaround_time;
} PCB;

PCB* create_process(int process_id,int priority = 0 ,float arrival_time = 0.0, float burst_time = 0.0);
void update_process_counter(PCB* process, int counter_value);
void display_process(PCB* process);
void free_process(PCB* process);
#endif
