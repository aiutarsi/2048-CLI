#include "process2048.h"
#include "shift/shiftMove/shiftUp.h"
#include "shift/shiftMove/shiftDown.h"
#include "shift/shiftMove/shiftLeft.h"
#include "shift/shiftMove/shiftRight.h"
#include "shift/judgeShiftUp.h"
#include "shift/judgeShiftDown.h"
#include "shift/judgeShiftLeft.h"
#include "shift/judgeShiftRight.h"
#include "judgeGameOver.h"
#include "judgeExist2048.h"
#include "generateNumberRandomly/generateNumberRandomly.h"
#include "generateNumberRandomly/generateNumberRandomlyAtFirst.h"
#include "printBoard/printBoard.h"
#include "readBoardSideSheets.h"
#include <stdio.h>
#include <stdlib.h>

int process2048(const int boardSize) {
  int board[8][8];
  int score = 0;

  /* printBoard of right part, sheets/boardSide.txt */
  char contentBoardSide[52][72];
  readBoardSideSheets(contentBoardSide);

  /* Random generate at first */
  generateNumberRandomlyAtFirst(boardSize, board);

  int keyboardInput = 't';

  do {
    /* direction judge */
    int judgeDirections[4] = {0,0,0,0};
    judgeDirections[0] = judgeShiftUp(boardSize, board);
    judgeDirections[1] = judgeShiftDown(boardSize, board);
    judgeDirections[2] = judgeShiftLeft(boardSize, board);
    judgeDirections[3] = judgeShiftRight(boardSize, board);
    
    /* 2048 judge */
    int flag2048 = judgeExist2048(boardSize, board);

    /* game over judge */
    int flagGameOver = judgeGameOver(judgeDirections);

    /* printBoard */
    printBoard(boardSize, board, score, 0, judgeDirections, contentBoardSide);

    int flagBreak = 1;
    while (flagBreak) {
      system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
      keyboardInput = getchar();
      system("/bin/stty cooked"); /* clean up */

      if (keyboardInput == 'i' && judgeDirections[0]) {
        score = shiftUp(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'm' && judgeDirections[1]) {
        score = shiftDown(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'j' && judgeDirections[2]) {
        score = shiftLeft(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'k' && judgeDirections[3]) {
        score = shiftRight(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == '.') {
        flagBreak = 0;
      }
    }
  } while(keyboardInput != '.');
  
  return 0;
}
