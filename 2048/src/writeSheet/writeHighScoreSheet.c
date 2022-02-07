#include "writeHighScoreSheet.h"
#include <stdio.h>
#include <stdlib.h>

void writeHighScoreSheet(int arrayHighScore[]) {
  FILE *fp;
  const char highScoreName[] = "./src/sheets/highScoreSheet.txt";

  if ((fp = fopen(highScoreName, "w")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", highScoreName);
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 5; i++) {
    fprintf(fp, "%d\n", arrayHighScore[i]);
  }

  fclose(fp);
}
