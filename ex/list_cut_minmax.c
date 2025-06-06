#include <limits.h>
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
 * Rimuove dalla lista i nodi con il valore minimo e i nodi con il valore massimo.
 */
node* list_cut_minmax(node* ls) {
  node* l = ls;
  int min = INT_MAX;
  int max = INT_MIN;

  while (l != NULL) {
    if (l->val < min) min = l->val;
    if (l->val > max) max = l->val;
    l = l->next;
  }

  l = ls;
  node* prev_min = NULL;
  while (l != NULL) {
    if (l->val == min) {
      prev_min->next = l->next;
    }
    prev_min = l;
    l = l->next;
  }

  l = ls;
  node* prev_max = NULL;
  while (l != NULL) {
    if (l->val == max) {
      prev_max->next = l->next;
    }
    prev_max = l;
    l = l->next;
  }

  return ls;
}

int main() {
  int a[] = {5, 4, 2, 8, 3, 7, 3};
  node* l = ArrayToList(a, sizeof(a) / sizeof(int));

  printf("Lista prima: ");
  printlist(l);

  printf("Lista dopo: ");
  printlist(list_cut_minmax(l));
}