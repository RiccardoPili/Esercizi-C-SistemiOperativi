#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Restituisce true se la stringa non contiene due caratteri uguali
 * ogni tre caratteri consecutivi.
 * Ad esempio, "ABCDAC" restituisce true, mentre "ABCABA" restituisce false.
 */
int all_3chars_diff(char *s) {
  if (s == NULL || s[0] == '\0') return false;
  if (s[1] == '\0') return true;
  if (s[0] == s[1]) return false;

  for (int i = 2; s[i] != '\0'; i++) {
    if (s[i - 2] == s[i] || s[i - 1] == s[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  char *test1 = "ABCDAC";  // Expected: true
  char *test2 = "ABCAB";   // Expected: true
  char *test3 = "ABCABA";  // Expected: false
  char *test4 = "ABCAZB";  // Expected: true
  char *test5 = "A";       // Expected: true

  printf("Test 1: %s --> %s\n", test1, all_3chars_diff(test1) ? "true" : "false");
  printf("Test 2: %s --> %s\n", test2, all_3chars_diff(test2) ? "true" : "false");
  printf("Test 3: %s --> %s\n", test3, all_3chars_diff(test3) ? "true" : "false");
  printf("Test 4: %s --> %s\n", test4, all_3chars_diff(test4) ? "true" : "false");
  printf("Test 5: %s --> %s\n", test5, all_3chars_diff(test5) ? "true" : "false");

  return 0;
}