#include "printBoardRightSideOrdinal.h"
#include <stdio.h>

void printBoardRightSideOrdinal(char line[]) {
  for (int i = 0; i < 70; i++) {
    if (line[i] == '#') {
      printf("\033[48;5;231m "); /* White space */
    }
    else {
      printf("\033[0m%c", line[i]); /* White alphabet OR Default space*/
    }
  }
  printf("\033[0m\n");
}
