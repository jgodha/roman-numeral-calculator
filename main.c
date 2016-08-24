#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "romanNumeralCalculator.h"

int main(void) {
  char *result = malloc(100);
  char a[20];
  char b[20];

  printf("Enter the first numeral: \n");
  fgets(a, 20, stdin);
  a[strcspn(a, "\n")] = 0;

  printf("Enter the second numeral: \n");
  fgets(b, 20, stdin);
  b[strcspn(b, "\n")] = 0;

  add(a, b, result);
  printf("%s+%s=%s\n", a, b, result);

  subtract(a, b, result);
  printf("%s-%s=%s\n", a, b, result);

  free(result);
  return 0;
}
