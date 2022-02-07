#include "calculateDigitNumber.h"

int calculateDigitNumber(int number) {
  int res = 0;
  if (!number) res++; /* case number == 0 but digit is 1*/
  while (number) {
    number /= 10;
    res++;
  }
  return res;
}
