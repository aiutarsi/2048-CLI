#include "printBoardRightSideGoBack.h"
#include <stdio.h>

void printBoardRightSideGoBack(char line[]) {
  for (int i = 0; i < 70; i++) {
    if (2 <= i && i <= 42) {
      printf("\033[48;5;160m");
    }
    else {
      printf("\033[0m");
    }
    printf("%c", line[i]);
  }
}
