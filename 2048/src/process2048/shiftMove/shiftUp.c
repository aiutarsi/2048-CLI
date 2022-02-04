#include "shiftUp.h"

int shiftUp(int boardSize, int board[][8], int beforeScore) {
  int addScore = 0;

  int nextBoard[boardSize+1][boardSize+1];
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      nextBoard[i][j] = 0;
    }
  }

  for (int i = 0; i < boardSize; i++) {
    int nowNumber = board[0][i];
    int nextBoardIndex = 0;
    int skipFlag = 0;

    for (int j = 1; j < boardSize; j++) {
      if (skipFlag) {
        skipFlag = 0;
        continue;
      }

      else {
        if (nowNumber != 0 && board[j][i] == nowNumber) {
          nextBoard[nextBoardIndex][i] = nowNumber*2;
          addScore += nowNumber*2;
          nextBoardIndex++;
          nowNumber = board[j+1][i];
          skipFlag = 1;
        }
        else if (nowNumber == 0 && board[j][i] != 0) {
          nowNumber = board[j][i];
        }
        else if (nowNumber != 0 && board[j][i] != nowNumber && board[j][i] != 0) {
          nextBoard[nextBoardIndex][i] = nowNumber;
          nextBoardIndex++;
          nowNumber = board[j][i];
        }
      }
    }

    if (!skipFlag) {
      nextBoard[nextBoardIndex][i] = nowNumber;
    }
  }

  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      board[i][j] = nextBoard[i][j];
    }
  }

  return beforeScore + addScore;
}
