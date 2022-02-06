#include "decimalToBinary.h"

int decimalToBinary(int number) { /* return binary number's length, Ex. 4 -> 3, 8 -> 4 */
  int digitCount;
  while(number) {
    digitCount++;
    number /= 2;
  }
  return digitCount;
}
