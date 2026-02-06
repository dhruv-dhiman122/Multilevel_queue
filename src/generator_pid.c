/*
 *  this file is the implemnation for generating pid for the process
 * */

#include <stdio.h>
#include <stdlib.h>
#include "shared_variable.h"
#include "process_counter.h"
//============================ Space for macro ============================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

//============================ space for user defined function ==================================

void sjfProcess() {
  process_counter.sjf_process = sjf_process_counter;
}

void fcfsProcess() {
  process_counter.fcfs_process = sjf_process_counter;
}

void totalProcess() {
  process_counter.total_process = process_counter.sjf_process + process_counter.fcfs_process;
}

//============================= Space for main function ==============================
int main() {

  exit(EXT_SUCCESS);
}
