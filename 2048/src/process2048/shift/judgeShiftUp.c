#include "judgeShiftUp.h"
#include "shiftMove/shiftUp.h"

int judgeShiftUp(int boardSize, int board[][8]) { /* 1 -> can shift up 0 -> cannot shift up */
  int copyBoard[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      copyBoard[i][j] = board[i][j];
    }
  }

  int returnScore = shiftUp(boardSize, copyBoard, 0);
  if (returnScore > 0) {
    return 1;
  }
  int flag = 1;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (copyBoard[i][j] != board[i][j]) { /* happend change */
        flag = 0;
        break;
      }
    }
    if (!flag) {
      break;
    }
  }
  if (flag) {
    return 0;
  }
  return 1;
}
