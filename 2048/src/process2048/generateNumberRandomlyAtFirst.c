#include "generateNumberRandomlyAtFirst.h"
#include <stdlib.h>
#include <sys/time.h>

void generateNumberRandomlyAtFirst(int boardSize, int board[][8]) { /* generate two 2 in random cell at first */
  struct timeval nowTime;
  gettimeofday(&nowTime, NULL);
  srand(((int)nowTime.tv_usec)%65536);
  int before = -1;
  int index = -1;
  for (int i = 0; i < 2; i++) {
    while (before == index) {
      int number = (int)rand();
      index = 1 + number%(boardSize*boardSize);
    }
    board[(index-1)/boardSize][(index-1)%boardSize] = 2;
    before = index;
  }
}
