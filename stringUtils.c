#include "stdlib.h"
#include "string.h"

void concatenate(char *a, char *b, char * result) {
    result[0] = '\0';
    strcat(result, a);
    strcat(result, b);
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

/* Below function has been copied from - http://stackoverflow.com/a/779960 */
char *str_replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep
    int len_with; // length of with
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    if (!orig)
        return NULL;
    if (!rep)
        rep = "";
    len_rep = strlen(rep);
    if (!with)
        with = "";
    len_with = strlen(with);

    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}
