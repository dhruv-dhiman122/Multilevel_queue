/*
 *  this file is the implemnation for generating pid for the process
 * */

#include <stdio.h>
#include <stdlib.h>
#include "shared_variable.h"

//============================ Space for macro ============================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

//================================ space for shared varaible to be used in process_control_block =======================

struct ProcessCounter {
  int sjf_process;
  int fcfs_process;
  int total_process;
};

struct ProcessCounter process_counter;

//============================= Space for user defined function ================

void sjfProcess() {
  process_counter.sjf_process = sjf_process_counter;
}

void fcfsProcess() {
  process_counter.fcfs_process = sjf_process_counter;
}

void totalProcess() {

}

//============================= Space for main function ==============================
int main() {

  exit(EXT_SUCCESS);
}
