#include "printBoxes.h"
#include <stdio.h>

void printBoxesUpperFrame(int boardSize, int eachRowBackgroundColorList[], int eachRowCharColorList[]) {
  for (int j = 0; j < boardSize; j++) { /* lines, each row */
    if (eachRowBackgroundColorList[j] > 0) {
      printf("\033[48;5;%dm", eachRowBackgroundColorList[j]);
      printf("\033[38;5;%dm", eachRowCharColorList[j]);
      printf("+----------+");
      printf("\033[0m");
    }
    else {
      printf("+----------+");
    }
  }
}

void printBoxesSideFrame(int boardSize, int eachRowBackgroundColorList[], int eachRowCharColorList[]) {
  for (int j = 0; j < boardSize; j++) { /* lines, each row */
    if (eachRowBackgroundColorList[j] > 0) {
      printf("\033[48;5;%dm", eachRowBackgroundColorList[j]);
      printf("\033[38;5;%dm", eachRowCharColorList[j]);
      printf("|          |");
      printf("\033[0m");
    }
    else {
      printf("|          |");
    }
  }
}
