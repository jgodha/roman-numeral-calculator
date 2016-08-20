#include "stdlib.h"
#include "string.h"
#include "stringUtils.h"
#include "romanNumeralCalculator.h"

/* TODO figure out how to declare these symbols in a Map-like structure */
const char ROMAN[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

const int NUM_OF_PATTERNS = 6;

char* COMPACT_PATTERNS[] = { "IX", "IV", "XC", "XL", "CM", "CD"};
char* UNCOMPACT_PATTERNS[] = { "VIIII", "IIII", "LXXXX", "XXXX", "DCCCC", "CCCC" };

char* GROUPS[] = { "V", "X", "L", "C", "D", "M" };
char* GROUP_MEMBERS[] = { "IIIII", "VV", "XXXXX", "LL", "CCCCC", "DD" };

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

char* group(char *a) {
  int i;
  for (i=0; i<6; i++) {
    a = str_replace(a, GROUP_MEMBERS[i], GROUPS[i]);
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

void removeSpaces(char str[]) {
  int count = 0;
  int i;
  for(i=0; i< strlen(str); i++) {
    if(str[i] != ' ') {
      str[count++] = str[i];
    }
  }
  str[count] = '\0';
}

void removeMatchingChars(char a[], char b[]) {
  int lenA = strlen(a);
  int lenB = strlen(b);
  int i, j;
  for(i=0; i<lenA; i++) {
    for(j=0; j<lenB; j++) {
      if(b[j] == a[i]) {
        b[j] = ' ';
        a[i] = ' ';
      }
    }
  }
  removeSpaces(a);
  removeSpaces(b);
}

char* ungroup(char *str) {
  int i;
  for (i=0; i<6; i++) {
    str = str_replace(str, GROUPS[i], GROUP_MEMBERS[i]);
  }
  return str;
}

void subtract(char a[], char b[], char* result) {
  a = uncompact(a);
  b = uncompact(b);
  removeMatchingChars(a, b);

  while(strlen(b) != 0) {
    a = ungroup(a);
    removeMatchingChars(a, b);
  }

  a = compact(group(a));

  strcpy(result, a);
}
