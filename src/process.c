/*
 * ============================================================================
 *            The aim of the file is to make a common ground 
 *            for simulation to make process.
 * ============================================================================
 * */

#include <stdio.h>
#include "process.h"
#include <stdlib.h>
#include <unistd.h>

// ============================ Space for defining macro ======================

#define EXT_SUCCESS 0
#define EXT_FAILURE 1

// ============================= Space for defining user function ==========================



// =========================== space for main function only ================================
int main() {
  printf("Enter the number of process you want to create\n");
  int user_process_number;
  scanf("%d",&user_process_number);
  printf("Enter the type of process you want to make; 1 for FCFS type and 2 for SJF\n");
  int process_type;
  scanf("%d",&process_type);

  return 0;
}
