#include "judgeExist2048.h"

int judgeExist2048(int boardSize, int board[][8]) { /* 1 -> 2048 exists. 0 -> 2048 doesn't exist */
  int flag = 0;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (board[i][j] >= 2048) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      break;
    }
  }
  if (flag) {
    return 1;
  }
  return 0;
}
