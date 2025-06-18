#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  int val;
  struct _node *next;
} node;

// ------------- metodi ausiliari --------------------
void printlist(node *l) {
  while (l != NULL) {
    printf("%d ", l->val);
    l = l->next;
  }
  printf("\n");
}

node *Cons(int x, node *xs) {
  node *newnode = malloc(sizeof(node));
  newnode->val = x;
  newnode->next = xs;
  return newnode;
}

node *ArrayToList(int A[], int n) {
  node *l = NULL;
  for (int i = n - 1; i >= 0; i--) {
    l = Cons(A[i], l);
  }
  return l;
}

// --- ESERCIZIO 1: solo caratteri minuscoli ----------------------------
char *only_minusc(char *str) {
  char *result = malloc(strlen(str) + 1);

  int j = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[j] = str[i];
      j++;
    }
  }

  result[j + 1] = '\0';

  result = realloc(result, j + 1);
  return result;
}

// --- ESERCIZIO 2: cancella il penultimo elemento dalla lista ----------
node *delete_2last(node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  node *sec_last = head;
  node *prev = NULL;

  while (sec_last->next->next != NULL) {
    prev = sec_last;
    sec_last = sec_last->next;
  }

  prev->next = sec_last->next;
  free(sec_last);

  return head;
}

int main() {
  char *str = "A3mHi9nusJc";
  printf("Stringa di partenza: %s\n", str);
  printf("OnlyMinus: %s\n", only_minusc(str));

  int arr1[] = {7, 3, 9, 3, 10, 1};
  node *l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(int));

  printf("Lista iniziale: ");
  printlist(l1);

  printf("Lista dopo delete_2last: ");
  printlist(delete_2last(l1));
}