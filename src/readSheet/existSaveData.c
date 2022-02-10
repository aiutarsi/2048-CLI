#include "existSaveData.h"
#include <stdio.h>
#include <stdlib.h>

int existSaveData(int boardSize) {
  FILE *fp;
  char saveDataName[] = "./.sheets/saveData/3.txt";
  saveDataName[19] = '0' + boardSize;

  if ((fp = fopen(saveDataName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", saveDataName);
    exit(EXIT_FAILURE);
  }

  int existSaveData = 0;
  fscanf(fp, "%d", &existSaveData);

  fclose(fp);
  if (!existSaveData) {
    return 0;
  }
  return 1;
}
