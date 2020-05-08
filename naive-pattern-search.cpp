
#include <stdio.h>
#include <string.h>

void searchPatter_novice(char *str, char *p);

void searchPatter_novice(char *str, char *p) {

  /**
   * length of the string and pattern
   */
  int pLen = strlen(p);
  int strLen = strlen(str);

  /**
   * variables
   */
  int Limit, i, j;

  Limit = strLen - pLen;

  for (i = 0; i <= Limit; i++) {
    for (j = 0; j < pLen; j++) {
      if(p[j] != str[i+j]) {
        break;
      }
    }
    if(j == pLen) {
      printf("Pattern found at position %d\n", i);
    }
  }
}

int main(void) {

  //the string
  char str[] = "AABAAAB";

  //pattern to search
  char p[] = "AA";

  //search for pattern
  searchPatter_novice(str, p);

  return 0;
}