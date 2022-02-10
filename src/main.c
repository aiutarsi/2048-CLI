#include "printFrontMenu/printFrontMenu.h"
#include "process2048/process2048.h"
#include "whichStart/whichStart.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int endThisGame = 1; /* if 0, finish this program */
  while (endThisGame) {

    int boardSize = printFrontMenu();

    if (boardSize == 8) {
      endThisGame = 0;
      continue;
    }

    int which = whichStart(boardSize);

    process2048(boardSize, which);
  }
}
