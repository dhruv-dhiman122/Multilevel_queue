/*
 * This is a common .h file for sharing the common things needed for making process
 * */



#ifndef PROCESS_H
#define PROCESS_H

typedef enum PROCESSTYPE {
  FCFS_type = 1,
  SJF_type = 2
} ProcessType;

typedef struct PROCESS {
  float arrival_time;
  float burst_time;
  ProcessType user_define_process;
  float wait_time;
} Process;

extern int total_process;
extern int fcfs_type_process;
extern int sjf_type_process;

#endif
