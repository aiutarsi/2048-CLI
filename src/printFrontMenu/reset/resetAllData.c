#include "resetAllData.h"
#include <stdio.h>
#include <stdlib.h>

void resetAllData() {
  /* highScoreSheet.txt reset */
  FILE *fpHigh;
  const char highScoreName[] = "./.sheets/highScoreSheet.txt";
  if ((fpHigh = fopen(highScoreName, "w")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", highScoreName);
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 5; i++) {
    fprintf(fpHigh, "%d\n", 0);
  }
  fclose(fpHigh);

  int sizeArray[5] = {3,4,5,6,7};

  /* saveData reset */
  for (int i = 0; i < 5; i++) {
    FILE *fpSave;
    char saveDataName[] = "./.sheets/saveData/3.txt";
    saveDataName[19] = '0' + sizeArray[i];
    if ((fpSave = fopen(saveDataName, "w")) == NULL) {
      fprintf(stderr, "ERROR : Cannot open %s.\n", saveDataName);
      exit(EXIT_FAILURE);
    }
    fprintf(fpSave, "%d\n", 0);
    fclose(fpSave);
  }

  /* historySaveData reset */
  for (int i = 0; i < 5; i++) {
    FILE *fpHistory;
    char historySaveDataName[] = "./.sheets/historySaveData/3.txt";
    historySaveDataName[26] = '0' + sizeArray[i];
    if ((fpHistory = fopen(historySaveDataName, "w")) == NULL) {
      fprintf(stderr, "ERROR : Cannot open %s.\n", historySaveDataName);
      exit(EXIT_FAILURE);
    }
    fprintf(fpHistory, "%d\n", 0);
    fclose(fpHistory);
  }
}
