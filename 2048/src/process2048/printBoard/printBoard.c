#include "printBoard.h"
#include "../../math/decimalToBinary.h"
#include "../../math/calculateDigitNumber.h"
#include "printBoardLeftSide/printBoxes.h"
#include "printBoardLeftSide/printFillSpace.h"
#include "printBoardRightSide/printBoardRightSide.h"
#include <stdio.h>

void printBoard(int boardSize, int board[][8], int score, int highScore, int judgeDirections[], char contentBoardSide[][72]) {
  int colorList[20] = {136,208,196,200,126,93,63,21,33,45,76,28,64,69,97,88,131,240,232}; /* TODO : for 2^31-1, need more color and beautiful to see */

  int lineNumber = 0;
  printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
  lineNumber++;
  printf("\n");

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

    printBoxesUpperFrame(boardSize, eachRowColorList); /* 1st row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowColorList); /* 2nd row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowColorList); /* 3rd row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
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
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowColorList); /* 5th row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowColorList); /* 6th row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
    lineNumber++;
    printf("\n");

    printBoxesUpperFrame(boardSize, eachRowColorList); /* 7th row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
    lineNumber++;
    printf("\n");
  }

  while(lineNumber < 52) {
    for (int j = 0; j < 90; j++) {
      printf(" ");
    }
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore);
    lineNumber++;
    printf("\n");
  }
}
