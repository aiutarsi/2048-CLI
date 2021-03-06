#include "readSaveData.h"
#include <stdio.h>
#include <stdlib.h>

int readSaveData(int boardSize, int board[][8], int *score) { /* return 1 -> exist, return 0 -> doesn't exit */
  FILE *fp;
  char saveDataName[] = "./.sheets/saveData/3.txt";
  saveDataName[19] = '0' + boardSize;

  if ((fp = fopen(saveDataName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", saveDataName);
    exit(EXIT_FAILURE);
  }

  int existSaveData = 0;
  fscanf(fp, "%d", &existSaveData);
  if (!existSaveData) {
    fclose(fp);
    return 0;
  }

  fscanf(fp, "%d", score);

  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      fscanf(fp, "%d", &(board[i][j]));
    }
  }

  fclose(fp);
  return 1;
}
