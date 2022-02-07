#include "printBoardRightSide.h"
#include "printBoardRightSideOrdinal.h"
#include "printBoardRightSideShiftArrow.h"
#include <stdio.h>

void printBoardRightSide(int lineNumber, char contentBoardSide[][72], int judgeDirections[]) {
  if (0 <= lineNumber && lineNumber <= 2) {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
  else if (3 <= lineNumber && lineNumber <= 8) {
    printBoardRightSideShiftArrow(lineNumber, contentBoardSide[lineNumber], judgeDirections);
  }
  else if (9 <= lineNumber && lineNumber <= 10) {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
  else if (11 <= lineNumber && lineNumber <= 15) {
    printBoardRightSideShiftArrow(lineNumber, contentBoardSide[lineNumber], judgeDirections);
  }
  else if (lineNumber == 16) {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
  else if (17 <= lineNumber && lineNumber <= 22) {
    printBoardRightSideShiftArrow(lineNumber, contentBoardSide[lineNumber], judgeDirections);
  }
  else {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
}
