#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_sel(char* s, char sel) {
  char* result = NULL;
  int i;

  for (; *s != '\0' && *s != sel; s++);

  if (*s == sel) {
    result = malloc(strlen(s) + 1);
    result[0] = sel;
    for (i = 1; s[i] != '\0' && s[i] != sel; i++) {
      result[i] = s[i];
    }
    result[i] = '\0';
  }
  return result;
}

int main() {
  char* s = "abcde fgcde";
  char sel = 'c';

  char* res = get_sel(s, sel);
  printf("Stringa: %s\n", s);
  printf("Carattere: %c\n", sel);
  printf("Sottostringa: %s\n", res);
}