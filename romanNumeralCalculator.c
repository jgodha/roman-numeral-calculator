#include "string.h"
#include "stdlib.h"
#include "romanNumeralCalculator.h"

char* add(char *a, char *b) {
    char *result = malloc(sizeof(a) + sizeof(b) + 1);
    strcat(result, a);
    strcat(result, b);
    return result;
}

char* uncompact(char *a) {
    return a;
}
