#include "fetchHistory.h"

void fetchHistory(int boardSize, int board[][8], int *score, int historyScore[], int historyBoard[][8][8], int *nowPtr, int historySize, int *stackSize) {
  if (*stackSize == 0) return;
  *score = historyScore[*nowPtr];
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      board[i][j] = historyBoard[*nowPtr][i][j];
    }
  }
  if (*nowPtr == 0) *nowPtr = historySize-1;
  else (*nowPtr)--;
  (*stackSize)--;
}
