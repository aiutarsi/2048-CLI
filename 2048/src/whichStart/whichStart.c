#include "whichStart.h"
#include "printWhichStart.h"
#include "../readSheet/existSaveData.h"
#include <stdio.h>
#include <stdlib.h>

int whichStart(int boardSize) { /* from the begining start -> 1, from save data start -> 0 */
  int isExistSaveData = existSaveData(boardSize);

  if (!isExistSaveData) {
    return 1;
  }

  int keyboardInput = 'm';
  int which = 0;

  do {
    system("clear"); /* removing all terminal output */

    printWhichStart(which);

    system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
    keyboardInput = getchar();
    system("/bin/stty cooked"); /* clean up */

    if (keyboardInput == 'i') {
      which = 1;
    }
    else if (keyboardInput == 'm') {
      which = 0;
    }
  } while (keyboardInput != '.');

  return which;
}
