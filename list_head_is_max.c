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
 * Modifica la lista in modo che il nodo con il valore massimo diventi
 * la testa della lista, e tutti i nodi dopo il nodo con il valore massimo
 * vengano spostati alla fine della lista.
 * (I nodi precedenti al max vengono mantenuti in fondo alla lista.)
 *
 * esempio:
 * Input:   1 -> 2 -> 6 -> 4 -> 5
 * Output:  6 -> 4 -> 5 -> 1 -> 2
 */
node* head_is_max(node* head) {
  node* curr = head;
  node* prev = NULL;
  node* curr_max = head;
  node* prev_max = NULL;

  while (curr != NULL) {
    if (curr->val > curr_max->val) {
      curr_max = curr;
      prev_max = prev;
    }
    prev = curr;
    curr = curr->next;
  }
  if (curr_max != head) {
    prev->next = head;
    prev_max->next = NULL;
  }

  return curr_max;
}

node* list_head_is_max2(node* head) {
  int max = INT_MIN;
  node* l = head;
  node* max_list = NULL;    // lista dal max in poi
  node* before_max = NULL;  // puntatore al predecessore del max

  // Trova il max e salva la lista max_list
  while (l != NULL) {
    if (l->val > max) {
      max = l->val;
      max_list = l;
    }
    l = l->next;
  }

  // Trova il puntatore al nodo prima di max
  l = head;
  while (l != NULL && l->next != max_list)
    l = l->next;
  before_max = l;

  // Taglia gli elementi dopo
  if (before_max != NULL) before_max->next = NULL;

  // Trova l'ultimo nodo di max_list
  node* last = max_list;
  while (last->next != NULL) {
    last = last->next;
  }

  // Unisce le due liste
  last->next = head;
  return max_list;
}

int main() {
  int arr1[] = {1, 2, 6, 4, 5};
  node* l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(int));

  printf("Lista iniziale:\t\t");
  printlist(l1);

  printf("Lista modificata:\t");
  printlist(head_is_max(l1));
}