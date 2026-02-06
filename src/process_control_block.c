/*
 This file is a implematation for process control block.
 The idea behind is that we need a track of process when made from either file
 */

#include <stdio.h>
#include <stdlib.h>
#include "shared_variable.h"
#include "process_control_block.h"
#include "process_counter.h"

//============================= space for macro or union =====================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

//============================== space for function made by the user ========================

void totalProcess() {
  if(process_counter.total_process > 0) {
    printf("The total number of process are %d\n",process_counter.total_process);
  }
  else {
    printf("The total numbre of process are 0\n");
  }
}

//=========================== space only for main function =========================
int main() {

  //function for the printing the total number of process
  totalProcess();
	exit(EXT_SUCCESS);
}
