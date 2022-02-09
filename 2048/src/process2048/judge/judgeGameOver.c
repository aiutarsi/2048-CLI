#include "judgeGameOver.h"

int judgeGameOver(int judgeDirections[]) { /* 1 -> GameOver, 0 -> not GameOver */
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (judgeDirections[i] == 1) {
      count++;
    }
  }
  if (count == 0) {
    return 1;
  }
  return 0;
}
