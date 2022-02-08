#include "process2048.h"
#include "shift/shiftMove/shiftUp.h"
#include "shift/shiftMove/shiftDown.h"
#include "shift/shiftMove/shiftLeft.h"
#include "shift/shiftMove/shiftRight.h"
#include "shift/judgeShiftUp.h"
#include "shift/judgeShiftDown.h"
#include "shift/judgeShiftLeft.h"
#include "shift/judgeShiftRight.h"
#include "judgeGameOver.h"
#include "judgeExist2048.h"
#include "judgeOverFlow.h"
#include "generateNumberRandomly/generateNumberRandomly.h"
#include "generateNumberRandomly/generateNumberRandomlyAtFirst.h"
#include "printBoard/printBoard.h"
#include "../readSheet/readBoardSideSheet.h"
#include "../readSheet/readHighScoreSheet.h"
#include "../readSheet/readSaveData.h"
#include "../writeSheet/writeHighScoreSheet.h"
#include "confirmSaveData/confirmSaveData.h"
#include <stdio.h>
#include <stdlib.h>

int process2048(const int boardSize, int which) {

  /* initialization */
  int board[8][8];
  int score = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = 0;
    }
  }
  int messageFlags[3] = {0,0,0}; /* 2048( 0 -> don't exist, 1 -> exist, 2 -> still exist), gameover, overflow */

  /* Making HighScore array */
  int arrayHighScore[5] = {0,0,0,0,0};
  readHighScoreSheet(arrayHighScore);
  int highScore = arrayHighScore[boardSize-3];

  /* printBoard of right part, sheets/boardSide.txt */
  char contentBoardSide[50][72];
  readBoardSideSheet(contentBoardSide);

  /* From the Save Data */
  if (!which) {
    readSaveData(boardSize, board, &score);
    if (judgeExist2048(boardSize, board)) {
      messageFlags[0] = 2;
    }
  }
  /* From the Begining */
  else {
    /* Random generate at first */
    generateNumberRandomlyAtFirst(boardSize, board);
  }

  int keyboardInput = 't';
  int forTheFirstTime = 0;
  int flagGameOver = 0; /* GameOver -> 1 */
  int flagOverFlow = 0; /* OverFlow -> 1 */

  do {
    system("clear"); /* removing all terminal output */

    int flagBreak = 1;
    
    /* Random generate */
    if (forTheFirstTime) {
      generateNumberRandomly(boardSize, board);
    }
    forTheFirstTime = 1;

    /* direction judge */
    int judgeDirections[4] = {0,0,0,0};
    judgeDirections[0] = judgeShiftUp(boardSize, board);
    judgeDirections[1] = judgeShiftDown(boardSize, board);
    judgeDirections[2] = judgeShiftLeft(boardSize, board);
    judgeDirections[3] = judgeShiftRight(boardSize, board);
    
    /* 2048 judge */
    if (messageFlags[0] == 0) {
      if (judgeExist2048(boardSize, board)) {
        messageFlags[0] = 1;
      }
    }
    else if (messageFlags[0] == 1) {
      messageFlags[0] = 2;
    }

    /* game over judge */
    flagGameOver = judgeGameOver(judgeDirections);
    messageFlags[1] = flagGameOver;

    /* over flow judge */
    flagOverFlow = judgeOverFlow(boardSize, board);
    messageFlags[2] = flagOverFlow;

    /* update high score */
    if (highScore < score) { 
      highScore = score;
      arrayHighScore[boardSize-3] = highScore;
      writeHighScoreSheet(arrayHighScore);
    }

    /* printBoard */
    printBoard(boardSize, board, score, highScore, judgeDirections, contentBoardSide, messageFlags);

    while (flagBreak) {
      system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
      keyboardInput = getchar();
      system("/bin/stty cooked"); /* clean up */

      if (keyboardInput == 'i' && judgeDirections[0]) {
        score = shiftUp(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'm' && judgeDirections[1]) {
        score = shiftDown(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'j' && judgeDirections[2]) {
        score = shiftLeft(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'k' && judgeDirections[3]) {
        score = shiftRight(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == '.') {
        int skip = 0;
        if (flagGameOver || flagOverFlow) skip = 1;
        confirmSaveData(boardSize, board, score, skip);
        flagBreak = 0;
      }
    }
  } while(keyboardInput != '.' && !flagGameOver && !flagOverFlow);
  
  return 0;
}
