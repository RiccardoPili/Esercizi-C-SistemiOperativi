#include <stdio.h>
#include <stdlib.h>

/**
 * Data una stringa che comincia con caratteri numerici, restituisce il
 * valore numerico in base 10 fino al primo carattere diverso da una cifra
 * Se il primo carattere non è una cifra restituisce zero
 */
unsigned long my_atoi(char *str) {
  if (str == NULL)
    return 0;

  unsigned long result = 0;
  for (int i = 0; (str[i] >= '0' && str[i] <= '9') && str[i] != '\0'; i++) {
    unsigned int valore_cifra = str[i] - '0';
    result = result * 10 + valore_cifra;
  }
  return result;
}

int main() {
  char *s1 = "345ciao";
  char *s2 = "0024";

  unsigned long val1 = my_atoi(s1);
  unsigned long val2 = my_atoi(s2);

  printf("val1 = my_atoi(\"%s\") = %lu\n", s1, val1);
  printf("val2 = my_atoi(\"%s\") = %lu\n", s2, val2);
  printf("Somma val1 + val2 = %lu\n", val1 + val2);
}
