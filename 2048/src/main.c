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
  int gameMode = 0;
  int endThisGame = 1; /* if 0, finish this program */
  int boardSize = 4;
  while (endThisGame) {
    endThisGame = 0;
    int boardSize = printFrontMenu();
    int returnValue = process2048(boardSize);
  }
}
