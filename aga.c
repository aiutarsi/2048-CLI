#include <stdio.h>

int main() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      const int v = i*16+j;
      printf("\033[48;5;%dm%2d\033[0m ", v, v);
    }
    printf("\n");
  }
  printf("\033[38;5;232m");
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      const int v = i*16+j;
      printf("\033[48;5;%dm%2d", v, v);
    }
    printf("\n");
  }
  printf("\033[0m");

  int colorList[20] = {136,208,196,200,126,93,63,21,33,45,76,28,64,69,97,88,131,240,232};

  for (int i = 0; i < 20; i++) {
    printf("\033[48;5;%dm%2d ", colorList[i], colorList[i]);
  }
  printf("\033[0m\n");

  printf("\n");
  printf("\n");


  int newlist[30] = { 136, 208, 196, 200, 126, 
                      129, 93,  63,  21,  33, 
                      45,  76,  28,  46,  156,
                      226, 153, 81,  97,  213,
                      223, 88,  131, 17,  2,  
                      232, 235, 239, 244, 255}; /* 最後空白 -1 */
  int charlist[30] = {231, 231, 231, 231, 231,
                      231, 231, 231, 231, 231,
                      232, 232, 231, 232, 232,
                      232, 232, 232, 231, 232,
                      232, 231, 231, 231, 231,
                      231, 231, 231, 231, 232,};
  for (int i = 101; i < 131; i++) {
    printf("\033[38;5;%dm", charlist[i-101]);
    printf("\033[48;5;%dm%d", newlist[i-101], i);
    printf("\033[0m");
    printf(" ");
  }
  printf("\033[0m\n");
  printf("\n");
  printf("\n");
  printf("%d\n", (1<<30));


}
