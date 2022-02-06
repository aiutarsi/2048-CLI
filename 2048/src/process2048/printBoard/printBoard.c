#include "printBoard.h"
#include "decimalToBinary.h"
#include "calculateDigitNumber.h"
#include "printBoardLeftSide/printBoxes.h"
#include <stdio.h>

void printBoard(int boardSize, int board[][8], int score, int highScore, int judgeDirections[]) {
  int colorList[20] = {136,208,196,200,126,93,63,21,33,45,76,28,64,69,97,88,131,240,232}; /* TODO : for 2^31-1, need more color and beautiful to see */

  int lineNumber = 0;

  printf("\n");
  lineNumber++;

  for (int i = 0; i < boardSize; i++) { /* rows */
    int eachRowColorList[boardSize+1]; /* color each cell */
    for (int j = 0; j < boardSize; j++) { /* lines */
      eachRowColorList[j] = -1;
    }

    for (int j = 0; j < boardSize; j++) { /* lines */
      if (board[i][j] != 0) {
        eachRowColorList[j] = colorList[decimalToBinary(board[i][j])-2];
      }
    }

    for (int j = 0; j < boardSize; j++) { /* lines, 1st row */
      if (eachRowColorList[j] > 0) {
        printf("\e[48;5;%dm", eachRowColorList[j]);
        printf("+----------+");
        printf("\e[49m");
      }
      else {
        printf("+----------+");
      }
    }
    /* space fill */
    /* side board print */
    lineNumber++;
    printf("\n");

    for (int j = 0; j < boardSize; j++) { /* lines, 2nd row */
      if (eachRowColorList[j] > 0) {
        printf("\e[48;5;%dm", eachRowColorList[j]);
        printf("|          |");
        printf("\e[49m");
      }
      else {
        printf("|          |");
      }
    }
    /* space fill */
    /* side board print */
    lineNumber++;
    printf("\n");

    for (int j = 0; j < boardSize; j++) { /* lines, 3rd row */
      if (eachRowColorList[j] > 0) {
        printf("\e[48;5;%dm", eachRowColorList[j]);
        printf("|          |");
        printf("\e[49m");
      }
      else {
        printf("|          |");
      }
    }
    /* space fill */
    /* side board print */
    lineNumber++;
    printf("\n");

    for (int j = 0; j < boardSize; j++) { /* lines, 4th row */
      if (board[i][j] == 0) {
        printf("|          |");
      }
      else {
        printf("\e[48;5;%dm", eachRowColorList[j]);
        int length = calculateDigitNumber(board[i][j]); /* cell's number's length in decimal */
        switch (length) {
          case 1:
            printf("|    %d     |", board[i][j]);
            break;
          case 2:
            printf("|    %d    |", board[i][j]);
            break;
          case 3:
            printf("|   %d    |", board[i][j]);
            break;
          case 4:
            printf("|   %d   |", board[i][j]);
            break;
          case 5:
            printf("|  %d   |", board[i][j]);
            break;
          case 6:
            printf("|  %d  |", board[i][j]);
            break;
          case 7:
            printf("| %d  |", board[i][j]);
            break;
          case 8:
            printf("| %d |", board[i][j]);
            break;
          case 9:
            printf("|%d |", board[i][j]);
            break;
          case 10:
            printf("|%d|", board[i][j]);
            break;
          default:
            break;
        }
        printf("\e[49m");
      }
    }
    /* space fill */
    /* side board print */
    lineNumber++;
    printf("\n");

    for (int j = 0; j < boardSize; j++) { /* lines, 5th row */
      if (eachRowColorList[j] > 0) {
        printf("\e[48;5;%dm", eachRowColorList[j]);
        printf("|          |");
        printf("\e[49m");
      }
      else {
        printf("|          |");
      }
    }
    /* space fill */
    /* side board print */
    lineNumber++;
    printf("\n");

    for (int j = 0; j < boardSize; j++) { /* lines, 6th row */
      if (eachRowColorList[j] > 0) {
        printf("\e[48;5;%dm", eachRowColorList[j]);
        printf("|          |");
        printf("\e[49m");
      }
      else {
        printf("|          |");
      }
    }
    /* space fill */
    /* side board print */
    lineNumber++;
    printf("\n");

    for (int j = 0; j < boardSize; j++) { /* lines, 7th row */
      if (eachRowColorList[j] > 0) {
        printf("\e[48;5;%dm", eachRowColorList[j]);
        printf("+----------+");
        printf("\e[49m");
      }
      else {
        printf("+----------+");
      }
    }
    /* space fill */
    /* side board print */
    lineNumber++;
    printf("\n");
  }

  /* side board print */
}
