#include "generateNumberRandomly.h"
#include "stdlib.h"
#include "sys/time.h"

/* generate a random number in random cell every shifting */
int generateNumberRandomly(int boardSize, int board[][8]) { /* 1 -> generated successfully,  0 -> cannot generate because all cell isn't 0 */
  int enumBoard[boardSize+1][boardSize+1];
  int count = 0;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (board[i][j] == 0) {
        count++;
        enumBoard[i][j] = count;
      }
      else {
        enumBoard[i][j] = 0;
      }
    }
  }

  if (count == 0) {
    return 0;
  }

  struct timeval nowTime;
  gettimeofday(&nowTime, NULL);
  srand(((int)nowTime.tv_usec) % 65536); /* Random seed */
  int number = (int)rand();
  int index = 1 + number % count;

  int flag = 0;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (enumBoard[i][j] == num) {
        if (number % 100 == 99) { /* 1% -> 8 */
          board[i][j] = 8;
        }
        else if (number % 100 >= 90) { /* 9% -> 4 */
          board[i][j] = 4;
        }
        else {
          board[i][j] = 2; /* 90% -> 2 */
        }
        flag = 1;
        break;
      }
    }
    if (flag) {
      break;
    }
  }

  return 1;
}
