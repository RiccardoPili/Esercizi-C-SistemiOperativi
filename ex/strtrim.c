#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* VERSIONE CHE MANTIENE SOLO QUELLI TRA START E END*/
/**
 * strtrim - Rimuove i caratteri non compresi tra gli indici start e end
 */
char* strtrim(char* s, int start, int end) {
  if (s == NULL || start > end || start < 0 || end < 0 || end > strlen(s)) {
    perror("Errore nell'utilizzo di strtrim");
    exit(EXIT_FAILURE);
  }

  char* result = malloc(end - start + 1);
  int i;

  for (i = 0; i < start; i++);

  int j = 0;
  for (; i <= end; i++) {
    result[j] = s[i];
    j++;
  }

  result[j + 1] = '\0';
  return result;
}

/* VERSIONE CHE MANTIENE SOLO QUELLI NON COMPRESI TRA START E END*/
/**
 * strtrim2 - Rimuove i caratteri tra gli indici start e end inclusi
 */
char* strtrim_opposite(char* s, int start, int end) {
  if (s == NULL || start > end || start < 0 || end < 0 || end > strlen(s)) {
    perror("Errore nell'utilizzo di strtrim_opposite");
    exit(EXIT_FAILURE);
  }

  char* result = malloc(strlen(s) + 1);
  int i;

  int j = 0;
  for (i = 0; i < start; i++) {
    result[i] = s[i];
    j++;
  }

  for (; i <= end; i++);

  for (; i < strlen(s); i++) {
    result[j] = s[i];
    j++;
  }

  result[j + 1] = '\0';

  char* resized_result = realloc(result, j + 1);
  return resized_result;
}

int main() {
  char* s = "SISTEMI OPERATIVI";
  printf("Stringa iniziale: %s\n", s);
  char* res = strtrim(s, 2, 10);
  char* res2 = strtrim_opposite(s, 2, 10);
  printf("strtim(2, 10): %s\n", res);
  printf("strtrim_opposite(2, 10): %s\n", res2);
}