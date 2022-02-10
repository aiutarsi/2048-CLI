#include "printBoardRightSide.h"
#include "printBoardRightSideOrdinal.h"
#include "printBoardRightSideShiftArrow.h"
#include "printBoardRightSideScore.h"
#include "printBoardRightSideGoBack.h"
#include "printBoardRightSideUndoArrow.h"
#include <stdio.h>

void printBoardRightSide(int lineNumber, char contentBoardSide[][72], int judgeDirections[], int score, int highScore, int stackSize) {
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
  else if (23 <= lineNumber && lineNumber <= 25) {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
  else if (lineNumber == 26) {
    printBoardRightSideScore(contentBoardSide[lineNumber], score);
  }
  else if (lineNumber == 27) {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
  else if (lineNumber == 28) {
    printBoardRightSideScore(contentBoardSide[lineNumber], highScore);
  }
  else if (29 <= lineNumber && lineNumber <= 31) {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
  else if (32 <= lineNumber && lineNumber <= 36) {
    printBoardRightSideUndoArrow(lineNumber, contentBoardSide[lineNumber], stackSize);
  }
  else if (37 <= lineNumber && lineNumber <= 38) {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
  else if (39 <= lineNumber && lineNumber <= 44) {
    printBoardRightSideGoBack(contentBoardSide[lineNumber]);
  }
  else {
    printBoardRightSideOrdinal(contentBoardSide[lineNumber]);
  }
}
