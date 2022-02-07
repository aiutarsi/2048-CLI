#include "readBoardSideSheets.h"
#include <stdio.h>
#include <stdlib.h>

void readBoardSideSheets(int contentBoardSide[][72]) {
  FILE *fp;
  const char boardSideName[] = "./src/sheets/boardSide.txt";
  if ((fp = fopen(boardSideName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", boardSideName);
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < 52; i++) {
    if (fgets(contentBoardSide[i], 72, fp) == NULL) {
      fprintf(stderr, "ERROR : Invalid Format of %s (too few lines).\n", boardSideName);
      exit(EXIT_FAILURE);
    }
  }
  fclose(fp);
}