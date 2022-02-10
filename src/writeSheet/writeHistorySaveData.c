#include "writeHistorySaveData.h"
#include <stdio.h>
#include <stdlib.h>

void writeHistorySaveData(int boardSize, int historyScore[], int historyBoard[][8][8], int *stackSize, int *nowPtr, int historySize) {
  FILE * fp;
  char historySaveDataName[] = "./.sheets/historySaveData/3.txt";
  historySaveDataName[26] = '0' + boardSize;

  if ((fp = fopen(historySaveDataName, "w")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", historySaveDataName);
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%d\n", 1);
  fprintf(fp, "%d\n", *stackSize);
  fprintf(fp, "%d\n", *nowPtr);

  int now = *nowPtr;
  for (int i = 0; i < *stackSize; i++) {
    fprintf(fp, "%d\n", historyScore[now]);
    if (now == 0) now = historySize-1;
    else now--;
  }
  now = *nowPtr;
  for (int i = 0; i < *stackSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      for (int k = 0; k < boardSize; k++) {
        fprintf(fp, "%d\n", historyBoard[now][j][k]);
      }
    }
    if (now == 0) now = historySize-1;
    else now--;
  }

  fclose(fp);
}
