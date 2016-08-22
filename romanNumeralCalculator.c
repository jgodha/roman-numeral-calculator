#include "stdlib.h"
#include "string.h"
#include "stringUtils.h"
#include "romanSymbolUtils.h"
#include "romanNumeralCalculator.h"

void add(char *a, char *b, char* result) {
  concatenate(uncompact(a), uncompact(b), result);

  char *output = sortByValueDescending(result);

  output = compact(group(output));

  strcpy(result, output);
}

void subtract(char a[], char b[], char* result) {
  a = uncompact(a);
  b = uncompact(b);
  removeMatchingChars(a, b);

  while(strlen(b) != 0) {
    //TODO handle the case when b > a
      a = ungroup(a);
      removeMatchingChars(a, b);
  }

  a = compact(group(a));

  strcpy(result, a);
}
