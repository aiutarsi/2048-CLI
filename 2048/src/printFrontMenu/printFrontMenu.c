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

  /* file open */
  if ((fpFrontMenu = fopen(frontMenuName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", frontMenuName);
    exit(EXIT_FAILURE);
  }

  /* save the content to 2-dim array from txt file */
  const size_t rowsLength = 50;
  const size_t linesLength = 162;
  char contentFrontMenu[rowsLength][linesLength]; /* content from frontMenu.txt */
  for (int i = 0; i < rowsLength; i++) {
    if (fgets(contentFrontMenu[i], linesLength, fpFrontMenu) == NULL) {
      fprintf(stderr, "ERROR : Invalid Format of %s (too few lines).\n", frontMenuName);
      exit(EXIT_FAILURE);
    }
  }

  int startScore = 42;
  int widthScore = 5;
  int startBoardSize = 32;
  int widthBoardSize = 7;
  int selectedBoardSize = 4;

  int keyboardInput = 'i';

  do { /* loop until typing Enter key */
    system("clear"); /* removing all terminal output */

    /* update board size by keyboard input */
    if (keyboardInput == 'j') {
      selectedBoardSize--;
    }
    else if (keyboardInput == 'k') {
      selectedBoardSize++;
    }
    if (selectedBoardSize == 2 && keyboardInput == 'j') { /* Before 3 and <- */
      selectedBoardSize = 3;
    }
    else if (selectedBoardSize == 9 && keyboardInput == 'k') { /* Before x and -> */
      selectedBoardSize = 8;
    }

    for (int i = 0; i < rowsLength; i++) {
      if (startScore <= i && i < startScore+widthScore) {
        printFrontMenuHighScore(contentFrontMenu[i], arrayHighScore[i-startScore]);
      }
      else if (startBoardSize <= i && i < startBoardSize+widthBoardSize) {
        printFrontMenuBoardSize(contentFrontMenu[i],selectedBoardSize);
      }
      else {
        printFrontMenuOrdinal(contentFrontMenu[i]);
      }
    }
    system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
    keyboardInput = getchar();
    system("/bin/stty cooked"); /* clean up */

  } while (keyboardInput != '.');

  fclose(fpFrontMenu);

  return selectedBoardSize;
}
