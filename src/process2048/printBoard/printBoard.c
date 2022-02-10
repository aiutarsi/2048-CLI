#include "printBoard.h"
#include "../../math/decimalToBinary.h"
#include "../../math/calculateDigitNumber.h"
#include "printBoardLeftSide/printBoxes.h"
#include "printBoardLeftSide/printFillSpace.h"
#include "printBoardRightSide/printBoardRightSide.h"
#include "printBoardMessage.h"
#include <stdio.h>

void printBoard(int boardSize, int board[][8], int score, int highScore, int judgeDirections[], char contentBoardSide[][72], int messageFlags[], int stackSize) {
  int backgroundColorList[30] = { 136, 208, 196, 200, 126, 
                                  129, 93,  63,  21,  33, 
                                  45,  76,  28,  46,  156,
                                  226, 153, 81,  97,  213,
                                  223, 88,  131, 17,  2,  
                                  232, 235, 239, 244, 255}; /* background color */
  int charColorList[30] = { 231, 231, 231, 231, 231,
                            231, 231, 231, 231, 231,
                            232, 232, 231, 232, 232,
                            232, 232, 232, 231, 232,
                            232, 231, 231, 231, 231,
                            231, 231, 231, 231, 232,}; /* character color (white or black) */

  int lineNumber = 0;
  printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
  lineNumber++;
  printf("\n");

  for (int i = 0; i < boardSize; i++) { /* rows */
    int eachRowBackgroundColorList[boardSize]; /* background color each cell */
    int eachRowCharColorList[boardSize]; /* char color each cell */
    for (int j = 0; j < boardSize; j++) { /* lines */
      eachRowBackgroundColorList[j] = -1;
      eachRowCharColorList[j] = -1;
    }

    for (int j = 0; j < boardSize; j++) { /* lines */
      if (board[i][j] != 0) {
        eachRowBackgroundColorList[j] = backgroundColorList[decimalToBinary(board[i][j])-2];
        eachRowCharColorList[j] = charColorList[decimalToBinary(board[i][j])-2];
      }
    }

    printBoxesUpperFrame(boardSize, eachRowBackgroundColorList, eachRowCharColorList); /* 1st row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowBackgroundColorList, eachRowCharColorList); /* 2nd row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowBackgroundColorList, eachRowCharColorList); /* 3rd row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");

    for (int j = 0; j < boardSize; j++) { /* lines, 4th row */
      if (board[i][j] == 0) {
        printf("|          |");
      }
      else {
        printf("\033[48;5;%dm", eachRowBackgroundColorList[j]);
        printf("\033[38;5;%dm", eachRowCharColorList[j]);
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
        printf("\033[0m");
      }
    }
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowBackgroundColorList, eachRowCharColorList); /* 5th row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");

    printBoxesSideFrame(boardSize, eachRowBackgroundColorList, eachRowCharColorList); /* 6th row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");

    printBoxesUpperFrame(boardSize, eachRowBackgroundColorList, eachRowCharColorList); /* 7th row */
    printFillSpace(boardSize);
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");
  }

  while(lineNumber < 50) {
    for (int j = 0; j < 90; j++) {
      printf(" ");
    }
    printBoardRightSide(lineNumber, contentBoardSide, judgeDirections, score, highScore, stackSize);
    lineNumber++;
    printf("\n");
  }

  printBoardMessage(messageFlags);
}
