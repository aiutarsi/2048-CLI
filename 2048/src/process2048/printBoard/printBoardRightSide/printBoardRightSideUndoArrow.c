#include "printBoardRightSideUndoArrow.h"
#include "../../../math/calculateDigitNumber.h"
#include <stdio.h>

void printBoardRightSideUndoArrow(int lineNumber, char line[], int stackSize) {
  if (lineNumber == 34) {
    int i = 0;
    while (i < 70) {
      if (i == 30) {
        printf("\033[0m%d", stackSize);
        i += calculateDigitNumber(stackSize)-1;
      }
      else {
        if (line[i] == '#' && stackSize > 0) {
          printf("\033[48;5;160m "); /* Red space */
        }
        else {
          printf("\033[0m "); /* Default space */
        }
      }
      i++;
    }
  }
  else {
    for (int i = 0; i < 70; i++) {
      if (line[i] == '#' && stackSize > 0) {
        printf("\033[48;5;160m "); /* Red space */
      }
      else {
        printf("\033[0m "); /* Default space */
      }
    }
  }
  printf("\033[0m");
}
