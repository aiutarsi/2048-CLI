#include "printFrontMenu/printFrontMenu.h"
#include "process2048/process2048.h"
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
    process2048(boardSize);
  }
}
