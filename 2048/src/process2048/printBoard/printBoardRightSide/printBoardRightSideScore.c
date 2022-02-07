#include "printBoardRightSideScore.h"
#include "../../../math/calculateDigitNumber.h"
#include <stdio.h>

void printBoardRightSideScore(char line[], int score) {
  int printScoreFlag = 0;
  int i = 0;
  
  while (i < 70) {
    if (line[i] == ':') {
      printScoreFlag++;
      printf("\033[0m%c", line[i]); /* White alphabet */
    }
    else if (line[i] == ' ') {
      printf("\033[0m "); /* Default space */
    }
    else {
      printf("\033[0m%c", line[i]); /* White alphabet */
    }

    if (printScoreFlag) { /* write score after 2 space of ':' */
      if (printScoreFlag == 2) {
        printf("\033[38;5;1m%d", score); /* White score */
        i += calculateDigitNumber(score)-1;
        printScoreFlag = 0;
      }
      else {
        printScoreFlag++;
      }
    }

    i++;
  }
  printf("\033[0m");
}
