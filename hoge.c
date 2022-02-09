#include <stdio.h>
#include <stdlib.h>

typedef struct scoreboard {
  int Score;
  int Board[8][8];
} ScoreBoard;

int main() {
  ScoreBoard history[20];
  int nowPtr = 0;
  int endPtr = 0;
  history[0].Score = 2;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      history[0].Board[i][j] = 8*i+j;
    }
  }
  printf("%d, %d\n", history[0].Score, history[0].Board[3][4]);
}
