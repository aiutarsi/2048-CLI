#include "printBoxes.h"
#include <stdio.h>

void printBoxesUpperFrame(int boardSize, int eachRowColorList[]) {
  for (int j = 0; j < boardSize; j++) { /* lines, each row */
    if (eachRowColorList[j] > 0) {
      printf("\e[48;5;%dm", eachRowColorList[j]);
      printf("+----------+");
      printf("\e[49m");
    }
    else {
      printf("+----------+");
    }
  }
}

void printBoxesSideFrame(int boardSize, int eachRowColorList[]) {
  for (int j = 0; j < boardSize; j++) { /* lines, each row */
    if (eachRowColorList[j] > 0) {
      printf("\e[48;5;%dm", eachRowColorList[j]);
      printf("|          |");
      printf("\e[49m");
    }
    else {
      printf("|          |");
    }
  }
}
