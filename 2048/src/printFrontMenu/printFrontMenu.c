#include "printFrontMenu.h"
#include "readHighScoreSheet.h"
#include "printFrontMenuHighScore.h"
#include "printFrontMenuOrdinal.h"
#include "printFrontMenuBoardSize.h"
#include <stdio.h>
#include <stdlib.h>

int printFrontMenu() {
  /* Making HighScore array */
  int arrayHighScore[5] = {0,0,0,0,0};
  readHighScoreSheet(arrayHighScore);

  /* Reading frontMenu.txt and print */
  FILE *fpFrontMenu;
  const char frontMenuName[] = "./src/sheets/frontMenu.txt";

  if ((fpFrontMenu = fopen(frontMenuName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", frontMenuName);
    exit(EXIT_FAILURE);
  }

  const size_t bufsize = 162;
  char buf[bufsize];
  int i = 0;
  int startScore = 42;
  int widthScore = 5;
  int startBoardSize = 32;
  int widthBoardSize = 7;

  while (fgets(buf, bufsize, fpFrontMenu) != NULL && i < 50) {
    if (startScore <= i && i < startScore+widthScore) {
      printFrontMenuHighScore(buf, arrayHighScore[i-startScore]);
    }
    else if (startBoardSize <= i && i < startBoardSize+widthBoardSize) {
      printFrontMenuBoardSize(buf,3);
    }
    else {
      printFrontMenuOrdinal(buf);
    }
    i++;
  }

  fclose(fpFrontMenu);

  if (i > 50) {
    fprintf(stderr, "ERROR : Invalid Format of %s (too much lines).\n", frontMenuName);
    exit(EXIT_FAILURE);
  }

  return 4;
}
