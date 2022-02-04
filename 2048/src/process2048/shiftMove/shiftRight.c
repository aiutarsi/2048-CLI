#include "shiftRight.h"

int shiftRight(int boardSize, int board[][8], int beforeScore) {
  int addScore = 0;

  int nextBoard[boardSize+1][boardSize+1];
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      nextBoard[i][j] = 0;
    }
  }

  for (int i = 0; i < boardSize; i++) {
    int nowNumber = board[i][boardSize-1];
    int nextBoardIndex = boardSize-1;
    int skipFlag = 0;

    for (int j = boardSize-1-1; j > -1; j--) {
      if (skipFlag) {
        skipFlag = 0;
        continue;
      }

      else {
        if (nowNumber != 0 && board[i][j] == nowNumber) {
          nextBoard[i][nextBoardIndex] = nowNumber*2;
          addScore += nowNumber*2;
          nextBoardIndex--;
          nowNumber = board[i][j-1];
          skipFlag = 1;
        }
        else if (nowNumber == 0 && board[i][j] != 0) {
          nowNumber = board[i][j];
        }
        else if (nowNumber != 0 && board[i][j] != nowNumber && board[i][j] != 0) {
          nextBoard[i][nextBoardIndex] = nowNumber;
          nextBoardIndex--;
          nowNumber = board[i][j];
        }
      }
    }

    if (!skipFlag) {
      nextBoard[i][nextBoardIndex] = nowNumber;
    }
  }

  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      board[i][j] = nextBoard[i][j];
    }
  }

  return beforeScore + addScore;
}
