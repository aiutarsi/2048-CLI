#include "readBoardSideSheet.h"
#include <stdio.h>
#include <stdlib.h>

void readBoardSideSheet(char contentBoardSide[][72]) {
  FILE *fp;
  const char boardSideName[] = "./.sheets/boardSide.txt";
  if ((fp = fopen(boardSideName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", boardSideName);
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 50; i++) {
    if (fgets(contentBoardSide[i], 72, fp) == NULL) {
      fprintf(stderr, "ERROR : Invalid Format of %s (too few lines).\n", boardSideName);
      exit(EXIT_FAILURE);
    }
  }
  fclose(fp);
}
