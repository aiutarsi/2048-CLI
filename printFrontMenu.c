#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct front_menu {
  char *arrayFrontMenu[50];
} FrontMenu;

void printFrontMenu() {

}
*/



int main() {
  FILE *fp;
  const char frontMenuName[] = "./sheets/frontMenu.txt"; 

  if ((fp = fopen(frontMenuName, "r")) == NULL) {
    fprintf(stderr, "ERROR : Cannot open %s.\n", frontMenuName);
    exit(EXIT_FAILURE);
  }

  const size_t bufsize = 162;
  char buf[bufsize];
  char heightLimitation = 50;

  while (fgets(buf, bufsize, fp) != NULL && heightLimitation > -1) {
    heightLimitation--;
    printf("%s", buf);
  }

  if (heightLimitation < 0) {
    fprintf(stderr, "ERROR : Invalid Format of %s (too much lines).\n", frontMenuName);
    exit(EXIT_FAILURE);
  }
}
