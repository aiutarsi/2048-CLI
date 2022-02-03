#include "readHighScoreSheet.h"
#include <stdio.h>
#include <stdlib.h>

void readHighScoreSheet(int arrayHighScore[]) {
  FILE *fp;
  const char highScoreName[] = "./sheets/highScoreSheet.txt";

  if ((fp = fopen(highScoreName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", highScoreName);
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 5; i++) {
    fscanf(fp, "%d", &(arrayHighScore[i]));
  }

  fclose(fp);
}
