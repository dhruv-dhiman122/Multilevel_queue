#ifndef QUEUE_CONTROL_BLOCK_H
#define QUEUE_CONTROL_BLOCK_H

#include "process_control_block.h"

typedef enum {
	QUEUE_SJF,
	QUEUE_FCFS
} queueType;

typedef struct {
	PCB* process;
	int process_count;
	int capacity;
	queueType type;
	int process_completed;
	float total_executation_time;
	int current_program_counter;
}QCB;

#endif
