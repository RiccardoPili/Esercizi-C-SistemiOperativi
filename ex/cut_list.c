#include <stdio.h>
#include <stdlib.h>

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

// -------------- ESERCIZIO --------------------------

/**
 * Taglia la lista tra gli indici begin e end (inclusi).
 * Se begin è maggiore della lunghezza della lista, restituisce NULL.
 * Se end è maggiore della lunghezza della lista, taglia fino alla fine della lista.
 */
node *cut_list(node *head, int begin, int end) {
  node *p = head;
  node *temp = NULL;
  node *prev = NULL;
  int i;

  if (head == NULL) return NULL;

  // Cancella i nodi fino a begin
  for (i = 0; p != NULL && i < begin; i++) {
    temp = p;
    p = p->next;
    free(temp);
  }

  head = p;

  // Scorre i nodi compresi tra begin e end
  for (; p != NULL && i <= end; i++) {
    prev = p;
    p = p->next;
  }

  // Taglia la lista dopo end
  if (prev != NULL) {
    prev->next = NULL;  // fine lista -> next = NULL
  }
  // Libera i nodi dopo end
  while (p != NULL) {
    temp = p->next;
    free(p);
    p = temp;
  }

  return head;
}

int main() {
  int A[] = {1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(A) / sizeof(A[0]);

  node *list = ArrayToList(A, n);

  printf("Lista originale: ");
  printlist(list);

  int begin = 2, end = 5;
  node *cut_list = cutlist(list, begin, end);

  printf("Lista tagliata (da indice %d a %d): ", begin, end);
  printlist(cut_list);

  // Libera la memoria della lista tagliata
  while (cut_list != NULL) {
    node *temp = cut_list;
    cut_list = cut_list->next;
    free(temp);
  }
}