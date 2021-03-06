#include "printBoardMessage.h"
#include <stdio.h>

void printBoardMessage(int messageFlags[]) {
  printf("\033[38;5;160m");
  if (messageFlags[0] == 1) {
    printf("Congratulations! You succeeded in making 2048!\n");
  }
  if (messageFlags[1]) {
    printf("GameOver... Push '.' key and go back to Start Menu.\n");
  }
  if (messageFlags[2]) {
    printf("Wow! You made 1073741824(one step before of overflow Int). Push '.' key and go back to Start Menu\n");
  }
  printf("\033[0m");
}
