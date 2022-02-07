#include "decimalToBinary.h"

int decimalToBinary(int number) { /* return binary number's length, Ex. 4 -> 3, 8 -> 4 */
  int digitCount = 0;
  while(number) {
    digitCount++;
    number /= 2;
  }
  return digitCount;
}
