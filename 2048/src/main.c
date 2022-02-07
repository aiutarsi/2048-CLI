#include "printFrontMenu/printFrontMenu.h"
#include "process2048/process2048.h"
#include "whichStart/whichStart.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  /*
  0 -> Front Menu
  1 -> Game screen
  2 -> Game over screen
  */
  int endThisGame = 1; /* if 0, finish this program */
  while (endThisGame) {
    endThisGame = 0;

    int boardSize = printFrontMenu();

    if (boardSize == 8) continue;

    int which = whichStart(boardSize);
    
    process2048(boardSize);
  }
}
