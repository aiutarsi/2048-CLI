#include "printBoardRightSideShiftArrow.h"
#include <stdio.h>
#include <stdlib.h>

void printBoardRightSideShiftArrow(int lineNumber, char line[], int judgeDirections[]) {
  for (int i = 0; i < 70; i++) {
    if (3 <= lineNumber && lineNumber <= 8) { /* Up shift arrow */
      if (line[i] == '#' && judgeDirections[0]) {
        printf("\033[48;5;160m "); /* Red space */
      }
      else {
        printf("\033[0m%c", line[i]); /* Default space */
      }
    }

    else if (11 <= lineNumber && lineNumber <= 15) { /* Left & Right shift arrow */
      if (2 <= i && i <= 13+2) { /* Left Arrow */
        if (line[i] == '#' && judgeDirections[2]) {
          printf("\033[48;5;160m "); /* Red space */
        }
        else {
          printf("\033[0m%c", line[i]); /* Default space */
        }
      }
      else if (28-2 <= i && i <= 39+2) { /* Right Arrow */
      if (line[i] == '#' && judgeDirections[3]) {
          printf("\033[48;5;160m "); /* Red space */
        }
        else {
          printf("\033[0m%c", line[i]); /* Default space */
        }
      }
      else {
        printf("\033[0m%c", line[i]); /* Default space */
      }
    }

    else if (17 <= lineNumber && lineNumber <= 22) { /* Down shift arrow */
      if (line[i] == '#' && judgeDirections[1]) {
        printf("\033[48;5;160m "); /* Red space */
      }
      else {
        printf("\033[0m%c", line[i]); /* Default space */
      }
    }

    else {
      printf(stderr, "ERROR : Invalid calling at position printBoardRightSideShiftArrow().\n");
      exit(EXIT_FAILURE);
    }
  }
}
