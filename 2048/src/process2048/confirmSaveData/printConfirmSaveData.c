#include "printConfirmSaveData.h"
#include <stdio.h>

void printSpace(int start, int end) { /* [start, end) */
  for (int i = start; i < end; i++) printf(" ");
}
void printConfirmSaveData(int which) { /* 1 -> yes(save), 0 -> no(don't save) */
  for (int i = 0; i < 50; i++) {
    if ( 0 <= i <= 4) {
      printf("\n");
    }
    else if (i == 5) {
      printSpace(0, 49);
      printf("Do you go back to 'Start Menu' with saveing current game dat\n");
    }
    else if (i == 6) {
      printf("\n");
    }
    else if (i == 7) {
      printSpace(0, 15);
      printf("If type the 'i', your mouse cursor will move up.\n");
    }
    else if (i == 8) {
      printf("\n");
    }
    else if (i == 9) {
      printSpace(0, 15);
      printf("If type the 'm', your mouse cursor will move down.\n");
    }
    else if (i == 10) {
      printf("\n");
    }
    else if (i == 11) {
      printf("Push the '.' key and the game will start soon!\n");
    }
    else if (12 <= i && i <= 16) {
      printf("\n");
    }

    else if (17 <= i && i <= 19) {
      printSpace(0,60);
      if (which) {
        printf("\033[48;5;231m");
        printSpace(60, 100);
        printf("\033[0m");
      }
      printf("\n");
    }
    else if (i == 20) {
      printSpace(0, 60);
      if (which) {
        printf("\033[48;5;231m");
        printSpace(60, 72);
        printf("Yes : Save data");
        printSpace(87, 100);
        printf("\033[0m");
      }
      else {
        printSpace(60, 72);
        printf("Yes : Save data");
      }
      printf("\n");
    }
    else if (21 <= i && i <= 23) {
      printSpace(0,60);
      if (which) {
        printf("\033[48;5;231m");
        printSpace(60, 100);
        printf("\033[0m");
      }
      printf("\n");
    }

    else if (24 <= i && i <= 31) {
      printf("\n");
    }

    else if (32 <= i && i <= 34) {
      printSpace(0,60);
      if (!which) {
        printf("\033[48;5;231m");
        printSpace(60, 100);
        printf("\033[0m");
      }
      printf("\n");
    }
    else if (i == 35) {
      printSpace(0, 60);
      if (!which) {
        printf("\033[48;5;231m");
        printSpace(60, 70);
        printf("No : Don't save data");
        printSpace(90, 100);
        printf("\033[0m");
      }
      else {
        printSpace(60, 70);
        printf("No : Don't save data");
      }
      printf("\n");
    }
    else if (36 <= i && i <= 38) {
      printSpace(0,60);
      if (!which) {
        printf("\033[48;5;231m");
        printSpace(60, 100);
        printf("\033[0m");
      }
      printf("\n");
    }

    else {
      printf("\n");
    }
  }
}