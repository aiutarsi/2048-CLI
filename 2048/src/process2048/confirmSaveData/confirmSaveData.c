#include "confirmSaveData.h"
#include "printConfirmSaveData.h"
#include "../../writeSheet/writeSaveData.h"
#include <stdio.h>
#include <stdlib.h>

void confirmSaveData(int boardSize, int board[][8], int score, int skip) {
  if (skip) return;

  int keyboardInput = 'i';
  int which = 1;
  
  do {
    system("clear"); /* removing all terminal output */
    
    printConfirmSaveData(which);

    system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
    keyboardInput = getchar();
    system("/bin/stty cooked"); /* clean up */

    if (keyboardInput == 'i') {
      which = 1;
    }
    else if (keyboardInput == 'm') {
      which = 0;
    }

  } while(keyboardInput != '.');

  if (which) { /* save data(write to txt file) */
    writeSaveData(boardSize, board, score);
  }

}
