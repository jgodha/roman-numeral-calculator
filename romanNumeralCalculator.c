#include "stdlib.h"
#include "string.h"
#include "romanNumeralCalculator.h"

char* add(char *a, char *b) {
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

char* sortByValueDescending(char *a) {
    char *b = malloc(sizeof(a) + 1);
    strcpy(b, a);
    return b;
}
