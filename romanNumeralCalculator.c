#include "stdlib.h"
#include "string.h"
#include "stringUtils.h"
#include "romanNumeralCalculator.h"

/* TODO figure out how to declare these symbols in a Map-like structure */
const char ROMAN[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

const int NUM_OF_PATTERNS = 6;
char* COMPACT_PATTERNS[] = { "IV", "IX", "XL", "XC", "CD", "CM" };
char* UNCOMPACT_PATTERNS[] = { "IIII", "VIIII", "XXXX", "LXXXX", "CCCC", "DCCCC" };
char* GROUPABLE_PATTERNS[] = { "IIIII", "VV", "XXXXX", "LL", "CCCCC", "DD" };
char* GROUPS[] = { "V", "X", "L", "C", "D", "M" };

char* add(char *a, char *b) {
  char *result = sortByValueDescending(concatenate(uncompact(a), uncompact(b)));
  return compact(group(result));
}

char* uncompact(char *a) {
  int i;
  for (i=0; i<6; i++) {
    a = str_replace(a, COMPACT_PATTERNS[i], UNCOMPACT_PATTERNS[i]);
  }
  return a;
}

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

char* group(char *a) {
  int i;
  for (i=0; i<6; i++) {
    a = str_replace(a, GROUPABLE_PATTERNS[i], GROUPS[i]);
  }
  return a;
}

char* compact(char *a) {
  int i;
  for (i=0; i<6; i++) {
    a = str_replace(a, UNCOMPACT_PATTERNS[i], COMPACT_PATTERNS[i]);
  }
  return a;
}
