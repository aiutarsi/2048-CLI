#include "process2048.h"
#include "shift/shiftUp.h"
#include "shift/shiftDown.h"
#include "shift/shiftLeft.h"
#include "shift/shiftRight.h"
#include "judge/judgeShiftUp.h"
#include "judge/judgeShiftDown.h"
#include "judge/judgeShiftLeft.h"
#include "judge/judgeShiftRight.h"
#include "judge/judgeGameOver.h"
#include "judge/judgeExist2048.h"
#include "judge/judgeOverFlow.h"
#include "generateNumberRandomly/generateNumberRandomly.h"
#include "generateNumberRandomly/generateNumberRandomlyAtFirst.h"
#include "printBoard/printBoard.h"
#include "../readSheet/readBoardSideSheet.h"
#include "../readSheet/readHighScoreSheet.h"
#include "../readSheet/readSaveData.h"
#include "../readSheet/readHistorySaveData.h"
#include "../writeSheet/writeHighScoreSheet.h"
#include "confirmSaveData/confirmSaveData.h"
#include "history/recordHistory.h"
#include "history/fetchHistory.h"
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
  int historySize = 20;
  int historyBoard[historySize][8][8]; /* history for board */
  int historyScore[historySize]; /* history for score */
  int nowPtr = 0;
  int stackSize = 0;
  for (int i = 0; i < historySize; i++) {
    historyScore[i] = 0;
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        historyBoard[i][j][k] = 0;
      }
    }
  }

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
    readHistorySaveData(boardSize, historyScore, historyBoard, &stackSize, &nowPtr, historySize);
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
  int undoFlag = 0; /* undoFlag -> 1 did undo */

  do {
    system("clear"); /* removing all terminal output */

    int flagBreak = 1;
    
    /* Random generate */
    if (forTheFirstTime) {
      if (!undoFlag) {
        generateNumberRandomly(boardSize, board);
      }
      else {
        undoFlag = 0;
      }
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
    printBoard(boardSize, board, score, highScore, judgeDirections, contentBoardSide, messageFlags, stackSize);

    while (flagBreak) {
      system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
      keyboardInput = getchar();
      system("/bin/stty cooked"); /* clean up */

      if (keyboardInput == 'i' && judgeDirections[0]) {
        /* record History (necessary to call func here) */
        recordHistory(boardSize, board, score, historyScore, historyBoard, &nowPtr, 20, &stackSize);
        score = shiftUp(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'm' && judgeDirections[1]) {
        /* record History (necessary to call func here) */
        recordHistory(boardSize, board, score, historyScore, historyBoard, &nowPtr, 20, &stackSize);
        score = shiftDown(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'j' && judgeDirections[2]) {
        /* record History (necessary to call func here) */
        recordHistory(boardSize, board, score, historyScore, historyBoard, &nowPtr, 20, &stackSize);
        score = shiftLeft(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'k' && judgeDirections[3]) {
        /* record History (necessary to call func here) */
        recordHistory(boardSize, board, score, historyScore, historyBoard, &nowPtr, 20, &stackSize);
        score = shiftRight(boardSize, board, score);
        flagBreak = 0;
      }
      else if (keyboardInput == 'u' && stackSize != 0) {
        fetchHistory(boardSize, board, &score, historyScore, historyBoard, &nowPtr, historySize, &stackSize);
        undoFlag = 1;
        flagBreak = 0;
      }
      else if (keyboardInput == '.') {
        int skip = 0;
        if (flagGameOver || flagOverFlow) skip = 1;
        confirmSaveData(boardSize, board, score, skip, historyScore, historyBoard, &stackSize, &nowPtr, historySize);
        flagBreak = 0;
      }
    }
  } while(keyboardInput != '.' && !flagGameOver && !flagOverFlow);
  
  return 0;
}
