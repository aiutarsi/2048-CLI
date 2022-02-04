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

int process2048(const int boardSize) {
  int board[8][8];
  int score = 0;
  /* ランダム生成 */
  do {
    int judgeDirections[4] = {0,0,0,0};
    judgeDirections[0] = judgeShiftUp(boardSize, board);
    judgeDirections[1] = judgeShiftDown(boardSize, board);
    judgeDirections[2] = judgeShiftLeft(boardSize, board);
    judgeDirections[3] = judgeShiftRight(boardSize, board);
    //左
    //右
    //上
    //下
    //2048確認
    //gameover確認
    //表示
    //getcharここでwhile
    //ok
      //処理
    //ng
  } while();
  
}
