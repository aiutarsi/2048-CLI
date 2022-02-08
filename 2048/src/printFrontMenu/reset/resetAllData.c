#include "resetAllData.h"
#include <stdio.h>
#include <stdlib.h>

void resetAllData() {
  /* highScoreSheet.txt reset */
  FILE *fpHigh;
  const char highScoreName[] = "./src/sheets/highScoreSheet.txt";
  if ((fpHigh = fopen(highScoreName, "w")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", highScoreName);
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 5; i++) {
    fprintf(fpHigh, "%d\n", 0);
  }
  fclose(fpHigh);

  /* saveData reset */
  int sizeArray[5] = {3,4,5,6,7};
  for (int i = 0; i < 5; i++) {
    FILE *fpSave;
    char saveDataName[] = "./src/sheets/saveData/3.txt";
    saveDataName[22] = '0' + sizeArray[i];
    if ((fpSave = fopen(saveDataName, "w")) == NULL) {
      fprintf(stderr, "ERROR : Cannot open %s.\n", saveDataName);
      exit(EXIT_FAILURE);
    }
    fprintf(fpSave, "%d\n", 0);
    fclose(fpSave);
  }
}
