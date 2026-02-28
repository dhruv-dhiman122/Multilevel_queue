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
} Process;

#endif
