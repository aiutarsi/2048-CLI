#include "judgeShiftLeft.h"
#include "shiftMove/shiftLeft.h"

int judgeShiftLeft(int boardSize, int board[][8]) { /* 1 -> can shift left 0 -> cannot shift left */
  int copyBoard[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      copyBoard[i][j] = board[i][j];
    }
  }

  int returnScore = shiftLeft(boardSize, copyBoard, 0);
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
