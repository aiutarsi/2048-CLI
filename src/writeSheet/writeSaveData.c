#include "writeSaveData.h"
#include <stdio.h>
#include <stdlib.h>

void writeSaveData(int boardSize, int board[][8], int score) {
  FILE *fp;
  char saveDataName[] = "./.sheets/saveData/3.txt";
  saveDataName[19] = '0' + boardSize;

  if ((fp = fopen(saveDataName, "w")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", saveDataName);
    exit(EXIT_FAILURE);
  }

  fprintf(fp, "%d\n", 1);
  fprintf(fp, "%d\n", score);
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      fprintf(fp, "%d\n", board[i][j]);
    }
  }

  fclose(fp);
}
