#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Restituisce la sottostringa con i caratteri compresi tra
 * il primo carattere first e l'ultimo carattere last (inclusi).
 */
char* substr(char* s, char first, char last) {
  int i;
  char* result = malloc(strlen(s) + 1);

  // scorre fino a trovare first (posizione i)
  for (i = 0; s[i] != first; i++);

  // quando trova il primo scorre fino a trovare last e copia la stringa in result
  int j = 0;
  for (; s[i] != last; i++) {
    result[j] = s[i];
    j++;
  }

  // copia gli ultimi due caratteri
  result[j] = s[i];
  result[++j] = '\0';
  return result;
}

int main() {
  char* s = "Stringa da cui ricavare la sottostringa";
  printf("Stringa: %s\n", s);
  printf("Sottostringa: %s\n", substr(s, 'd', 't'));
}