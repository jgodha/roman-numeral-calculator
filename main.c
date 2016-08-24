#include "stdio.h"
#include "romanNumeralCalculator.h"
#include "stdlib.h"

int main(void) {
  char *result = malloc(100);

  char *a = "CCCLXIX";//"CXXIX";//"D";
  char *b = "DCCCXLV";//"XLIII";//"X";

  add(a, b, result);
  printf("a+b=%s\n", result);

  a = "D";//"CXXIX";//"D";
  b = "X";//"XLIII";//"X";
  subtract(a, b, result);
  printf("a-b=%s\n", result);

  free(result);
  return 0;
}
