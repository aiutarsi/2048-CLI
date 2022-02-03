#include "printFrontMenuOrdinal.h"
#include <stdio.h>

void printFrontMenuOrdinal(char line[]) { /* 2048 & explanation part */
  for (int i = 0; i < 160; i++) {
    if (line[i] == ' ') {
      printf("\033[0m "); /* Default space */
    }
    else if (line[i] == '#') {
      printf("\033[48;5;231m "); /* White space */
    }
    else {
      printf("\033[1m");
      printf("\033[0m%c", line[i]); /* White alphabet */
    }
  }
  printf("\033[0m\n");
}
