#include "resetInput.h"
#include <stdio.h>
#include <stdlib.h>

int resetInput() {
  int flag = 1;
  int before = 'r';
  int res = 0;
  int eFlag = 0;

  while(flag) {
    system("/bin/stty raw onlcr");  /* Enable to accept to input without typing Enter key */
    int keyboardInput = getchar();
    system("/bin/stty cooked"); /* clean up */
    if (before == 'r' && keyboardInput == 'e') {
      eFlag++;
      before = 'e';
      continue;
    }
    else if (eFlag == 1 && before == 'e' && keyboardInput == 's') {
      eFlag++;
      before = 's';
      continue;
    }
    else if (before == 's' && keyboardInput == 'e') {
      eFlag++;
      before = 'e';
      continue;
    }
    else if (eFlag == 3 && before == 'e' && keyboardInput == 't') {
      res = 1;
      flag = 0;
      break;
    }
    flag = 0;
  }

  return res;
}
