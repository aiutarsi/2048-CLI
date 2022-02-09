#include "recordHistory.h"

void recordHistory(int boardSize, int board[][8], int score, int historyScore[], int historyBoard[][8][8], int *nowPtr, int historySize, int *stackSize) {
  if (*stackSize != 0) { /* Not empty stack */
    *nowPtr = (*nowPtr+1)%historySize;
  }
  historyScore[*nowPtr] = score;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      historyBoard[*nowPtr][i][j] = board[i][j];
    }
  }
  *stackSize = ((*stackSize+1 >= historySize)? historySize : *stackSize+1);
}
