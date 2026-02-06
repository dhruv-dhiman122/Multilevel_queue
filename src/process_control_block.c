/*
 This file is a implematation for process control block.
 The idea behind is that we need a track of process when made from either file
 */

#include <stdio.h>
#include <stdlib.h>
#include "shared_variable.h"
#include "process_control_block.h"

//============================= space for macro or union =====================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

extern int sjf_program_counter;
extern int fcfs_program_counter;

//============================== space for function made by the user ========================


//=========================== space only for main function =========================
int main() {

	exit(EXT_SUCCESS);
}
