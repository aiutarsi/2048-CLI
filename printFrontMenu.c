#include <stdio.h>
#include <stdlib.h>


void printFrontMenuOrdinal(char line[]) { /* 2048 & explanation part */
  for (int i = 0; i < 160; i++) {
    if (line[i] == ' ') {
      printf("\033[0m "); /* Default space */
    }
    else if (line[i] == '#') {
      printf("\033[48;5;231m "); /* White space */
    }
    else {
      printf("\033[1m");
      printf("\033[0m%c", line[i]); /* White alphabet */
    }
  }
  printf("\033[0m\n");
}

int calculateDigitNumber(int number) {
  int res = 0;
  if (!number) res++; /* case number == 0 but digit is 1*/
  while (number) {
    number /= 10;
    res++;
  }
  return res;
}

void printFrontMenuHighScore(char line[], int score) {
  int printScoreFlag = 0;
  int i = 0;

  while (i < 160) {
    if (line[i] == ':') {
      printScoreFlag++;
      printf("\033[1m");
      printf("\033[0m%c", line[i]); /* White alphabet */
    }
    else if (line[i] == ' ') {
      printf("\033[0m "); /* Default space */
    }
    else {
      printf("\033[1m");
      printf("\033[0m%c", line[i]); /* White alphabet */
    }

    if (printScoreFlag) { /* write score after 2 space of ':' */
      if (printScoreFlag == 2) {
        printf("\033[1m");
        printf("\033[38;5;1m%d", score); /* White score */
        i += calculateDigitNumber(score)-1;
        printScoreFlag = 0;
      }
      else {
        printScoreFlag++;
      }
    }

    i++;
  }
  printf("\033[0m\n");
}

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

void printFrontMenu() {
  /* Making HighScore array */
  int arrayHighScore[5] = {0,0,0,0,0};
  readHighScoreSheet(arrayHighScore);

  /* Reading frontMenu.txt and print */
  FILE *fpFrontMenu;
  const char frontMenuName[] = "./sheets/frontMenu.txt";

  if ((fpFrontMenu = fopen(frontMenuName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", frontMenuName);
    exit(EXIT_FAILURE);
  }

  const size_t bufsize = 162;
  char buf[bufsize];
  int i = 0;
  int startScore = 40;

  while (fgets(buf, bufsize, fpFrontMenu) != NULL && i < 50) {
    if (startScore <= i && i <= startScore+4) {
      printFrontMenuHighScore(buf, arrayHighScore[i-startScore]);
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
}

int main() {
  printFrontMenu();
}
