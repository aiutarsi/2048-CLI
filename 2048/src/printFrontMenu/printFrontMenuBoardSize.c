#include "printFrontMenuBoardSize.h"
#include <stdio.h>

void printFrontMenuBoardSize(char line[], int selectedNumber) { /* 3~7, x print */
  int startColor = 0;
  int endColor = 0;
  switch (selectedNumber) {
    case 3:
      startColor = 26 + 19*0;
      break;
    case 4:
      startColor = 26 + 19*1;
      break;
    case 5:
      startColor = 26 + 19*2;
      break;
    case 6:
      startColor = 26 + 19*3;
      break;
    case 7:
      startColor = 26 + 19*4;
      break;
    case 8: /* 8 is x */
      startColor = 26 + 19*5;
      break;
    default:
      break;
  }
  endColor = startColor + 12;
  for (int i = 0; i < 160; i++) {
    if (startColor <= i && i < endColor) {
      if (line[i] == '#') {
        printf("\033[48;5;231m "); /* white space */
      }
      else {
        printf("\033[48;5;160m%c", line[i]); /* coloring background */
      }
    }
    else {
      if (line[i] == '#') {
        printf("\033[48;5;231m "); /* white space */
      }
      else {
        printf("\033[0m%c", line[i]);
      }
    }
  }
  printf("\033[0m\n");
}