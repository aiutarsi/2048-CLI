#include "judgeOverFlow.h"

int judgeOverFlow(int boardSize, int board[][8]) {
  int flag = 0;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (board[i][j] == -(1<<31)) {
        board[i][j] = -1;
        flag = 1;
      }
    }
  }
  if (flag) return 1;
  else return 0;
}
