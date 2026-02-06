/*
 * =============================================================================
 *                                  Note
 *   This file is made so that these properties can be shared between process_control_block.h file
 *   and generator_pid.c
 *
 *   This is the struct for process counting the number of process
 * =============================================================================
 * */

#ifndef PROCESS_COUNTER_H
#define PROCESS_COUNTER_H

struct ProcessCounter {
  int sjf_process;
  int fcfs_process;
  int total_process;
};

struct ProcessCounter process_counter;

#endif
