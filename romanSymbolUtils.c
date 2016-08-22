#include "stdlib.h"
#include "string.h"
#include "stringUtils.h"
#include "romanSymbolUtils.h"

const int NUM_OF_PATTERNS = 6;

char* COMPACT_PATTERNS[] = { "IX", "IV", "XC", "XL", "CM", "CD"};
char* UNCOMPACT_PATTERNS[] = { "VIIII", "IIII", "LXXXX", "XXXX", "DCCCC", "CCCC" };

char* GROUPS[] = { "V", "X", "L", "C", "D", "M" };
char* GROUP_MEMBERS[] = { "IIIII", "VV", "XXXXX", "LL", "CCCCC", "DD" };

char* compact(char *a) {
  int i;
  for (i=0; i<NUM_OF_PATTERNS; i++) {
    a = str_replace(a, UNCOMPACT_PATTERNS[i], COMPACT_PATTERNS[i]);
  }
  return a;
}

char* uncompact(char *a) {
  int i;
  for (i=0; i<NUM_OF_PATTERNS; i++) {
    a = str_replace(a, COMPACT_PATTERNS[i], UNCOMPACT_PATTERNS[i]);
  }
  return a;
}

char* group(char *a) {
  int i;
  for (i=0; i<NUM_OF_PATTERNS; i++) {
    a = str_replace(a, GROUP_MEMBERS[i], GROUPS[i]);
  }
  return a;
}

char* ungroup(char *str) {
  int i;
  for (i=0; i<NUM_OF_PATTERNS; i++) {
    str = str_replace(str, GROUPS[i], GROUP_MEMBERS[i]);
  }
  return str;
}

const char ROMAN[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

int findIndex(char value, const char array[]) {
   int i;
   int size = strlen(array);
   for (i=0; i<size; i++) {
  	 if (array[i] == value) {
  	    return i;
  	 }
   }
   return(-1);
}

int compare(const void *a, const void *b) {
    return findIndex(*(const char *)b, ROMAN) - findIndex(*(const char *)a, ROMAN);
}

char* sortByValueDescending(char *a) {
    qsort(a, strlen(a), 1, compare);
    return a;
}
