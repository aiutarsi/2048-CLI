#include "printFrontMenu/printFrontMenu.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  /*
  0 -> Front Menu
  1 -> Game screen
  2 -> Game over screen
  */
  int gameMode = 0;
  //system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
  int endThisGame = 1; /* if 0, finish this program */
  int boardSize = 4;
  while (endThisGame) {
    endThisGame = 0;
    int val = printFrontMenu();
    if (3 <= val && val <= 7) {
      boardSize = 4;
    }
    else if (val == 0) {
      endThisGame = 0;
    }
    else {
      fprintf(stderr, "ERROR : Invalid return value from printFromMenu Func");
      exit(EXIT_FAILURE);
    }
  }
  //system("/bin/stty cooked"); /* clean up */
}
