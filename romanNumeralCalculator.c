#include "stdlib.h"
#include "string.h"
#include "stringUtils.h"
#include "romanNumeralCalculator.h"
#include "stdio.h"

/* TODO figure out how to declare these symbols in a Map-like structure */
const char ROMAN[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

const int NUM_OF_PATTERNS = 6;
char* COMPACT_PATTERNS[] = { "IV", "IX", "XL", "XC", "CD", "CM" };
char* UNCOMPACT_PATTERNS[] = { "IIII", "VIIII", "XXXX", "LXXXX", "CCCC", "DCCCC" };
char* GROUPABLE_PATTERNS[] = { "IIIII", "VV", "XXXXX", "LL", "CCCCC", "DD" };
char* GROUPS[] = { "V", "X", "L", "C", "D", "M" };

char* concatenate(char *a, char *b) {
    char *result = malloc(sizeof(a) + sizeof(b) + 1);
    result[0] = '\0';
    strcat(result, a);
    strcat(result, b);
    return result;
}

int findIndex(char value) {
   int i;
   for (i=0; i<sizeof(ROMAN); i++) {
  	 if (ROMAN[i] == value) {
  	    return i;
  	 }
   }
   return(-1);
}

int compare(const void *a, const void *b) {
    return findIndex(*(const char *)b) - findIndex(*(const char *)a);
}

char* sortByValueDescending(char *a) {
    qsort(a, strlen(a), 1, compare);
    return a;
}

char* add(char *a, char *b) {
  int i;
  for (i=0; i<6; i++) {
    a = str_replace(a, COMPACT_PATTERNS[i], UNCOMPACT_PATTERNS[i]);
  }

  for (i=0; i<6; i++) {
    b = str_replace(b, COMPACT_PATTERNS[i], UNCOMPACT_PATTERNS[i]);
  }

  char *result = concatenate(a, b);

  result = sortByValueDescending(result);

  for (i=0; i<6; i++) {
    result = str_replace(result, GROUPABLE_PATTERNS[i], GROUPS[i]);
  }

  for (i=0; i<6; i++) {
    result = str_replace(result, UNCOMPACT_PATTERNS[i], COMPACT_PATTERNS[i]);
  }
  return result;
}
