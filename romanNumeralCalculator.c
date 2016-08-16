#include "stdlib.h"
#include "string.h"
#include "romanNumeralCalculator.h"

/* TODO figure out how to declare these symbols in a Map-like structure */
const char ROMAN[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };

char* concatenate(char *a, char *b) {
    char *result = malloc(sizeof(a) + sizeof(b) + 1);
    strcat(result, a);
    strcat(result, b);
    return result;
}

char* uncompact(char *a) {
    if(strcmp(a, "IV") == 0) return "IIII";
    if(strcmp(a, "IX") == 0) return "VIIII";
    if(strcmp(a, "XL") == 0) return "XXXX";
    if(strcmp(a, "XC") == 0) return "LXXXX";
    if(strcmp(a, "CD") == 0) return "CCCC";
    if(strcmp(a, "CM") == 0) return "DCCCC";
    return a;
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
    char *b = malloc(sizeof(a) + 1);
    strcpy(b, a);
    return b;
}

char* group(char* a) {
  if(strcmp(a, "IIIII") == 0) return "V";
  if(strcmp(a, "VV") == 0) return "X";
  if(strcmp(a, "XXXXX") == 0) return "L";
  if(strcmp(a, "LL") == 0) return "C";
  if(strcmp(a, "CCCCC") == 0) return "D";
  if(strcmp(a, "DD") == 0) return "M";
  return a;
}

char* compact(char *a) {
  if(strcmp(a, "IIII") == 0) return "IV";
  if(strcmp(a, "VIIII") == 0) return "IX";
  if(strcmp(a, "XXXX") == 0) return "XL";
  if(strcmp(a, "LXXXX") == 0) return "XC";
  if(strcmp(a, "CCCC") == 0) return "CD";
  if(strcmp(a, "DCCCC") == 0) return "CM";
  return a;
}
