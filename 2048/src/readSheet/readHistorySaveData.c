#include "readHistorySaveData.h"
#include <stdio.h>
#include <stdlib.h>

int readHistorySaveData(int boardSize, int historyScore [], int historyBoard[][8][8], int *stackSize, int *nowPtr, int historySize) { /* return 1 -> exist, return 0 -> doesn't exit */
  FILE *fp;
  char historySaveDataName[] = "./.sheets/historySaveData/3.txt";
  historySaveDataName[26] = '0' + boardSize;

  if ((fp = fopen(historySaveDataName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", historySaveDataName);
    exit(EXIT_FAILURE);
  }

  int existSaveData = 0;
  fscanf(fp, "%d", &existSaveData);
  if (!existSaveData) {
    fclose(fp);
    return 0;
  }

  fscanf(fp, "%d", stackSize);
  fscanf(fp, "%d", nowPtr);

  int now = *nowPtr;
  for (int i = 0; i < *stackSize; i++) {
    fscanf(fp, "%d", &(historyScore[now]));
    if (now == 0) now = historySize-1;
    else now--;
  }
  now = *nowPtr;
  for (int i = 0; i < *stackSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      for (int k = 0; k < boardSize; k++) {
        fscanf(fp, "%d", &(historyBoard[now][j][k]));
      }
    }
    if (now == 0) now = historySize-1;
    else now--;
  }

  fclose(fp);
  return 1;
}
