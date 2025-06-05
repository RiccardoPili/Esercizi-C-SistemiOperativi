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

// ------------- ESERCIZIO ---------------------------

node *list_invert(node *head) {
  node *prev = NULL;
  node *curr = head;
  node *n = NULL;

  while (curr != NULL) {
    n = curr->next;
    curr->next = prev;
    prev = curr;
    curr = n;
  }

  return prev;
}

node *list_invert_rec(node *head) {
  node *inverted = NULL;

  if (head == NULL || head->next == NULL) {
    return head;
  }
  inverted = list_invert_rec(head->next);
  head->next->next = head;
  head->next = NULL;

  return inverted;
}

int main() {
  int arr1[] = {1, 2, 3, 4, 5};
  node *l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(int));

  printf("Lista iniziale: ");
  printlist(l1);

  printf("Lista invertita: ");
  printlist(list_invert(l1));

  int arr2[] = {4, 5, 6, 7, 8};
  node *l2 = ArrayToList(arr2, sizeof(arr2) / sizeof(int));

  printf("\nLista iniziale: ");
  printlist(l2);

  printf("Lista invertita (versione ricorsiva): ");
  printlist(list_invert_rec(l2));
}