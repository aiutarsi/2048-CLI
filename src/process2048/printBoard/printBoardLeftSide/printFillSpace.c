#include "printFillSpace.h"
#include <stdio.h>

void printFillSpace(int boardSize) {
  for (int i = boardSize*12; i < 90; i++) {
    printf(" ");
  }
}
