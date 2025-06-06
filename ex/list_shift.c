#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int val;
  struct _node* next;
} node;

// ------------- metodi ausiliari --------------------
void printlist(node* l) {
  while (l != NULL) {
    printf("%d ", l->val);
    l = l->next;
  }
  printf("\n");
}

node* Cons(int x, node* xs) {
  node* newnode = malloc(sizeof(node));
  newnode->val = x;
  newnode->next = xs;
  return newnode;
}

node* ArrayToList(int A[], int n) {
  node* l = NULL;
  for (int i = n - 1; i >= 0; i--) {
    l = Cons(A[i], l);
  }
  return l;
}

// ------------- ESERCIZIO ---------------------------

/**
 * Sposta i nodi della lista di n posizioni a destra.
 *
 * esempio:
 * Input:   1 -> 2 -> 3 -> 4 -> 5, n = 2
 * Output:  4 -> 5 -> 1 -> 2 -> 3
 */
node* list_shift(node* ls, int n) {
  node* curr;
  int len;

  // scorre la lista e calcola length
  for (curr = ls, len = 1; curr->next != NULL; len++, curr = curr->next);

  n = n % len;
  if (n == 0) return ls;  // shift di n posizioni è come fare shift di zero posizioni

  curr->next = ls;  // rende la lista circolare

  n = len - n - 1;
  for (curr = ls; n > 0; n--, curr = curr->next);

  ls = curr->next;
  curr->next = NULL;  // termina la lista
  return ls;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  node* l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(int));

  printf("Lista iniziale: ");
  printlist(l1);

  printf("Lista shiftata di 2 posizioni: ");
  printlist(list_shift(l1, 2));
}