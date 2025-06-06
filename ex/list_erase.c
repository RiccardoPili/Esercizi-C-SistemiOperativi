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

// -------------- ESERCIZIO --------------------------

/**
 * Cancella dalla lista tutti i nodi che contengono il valore value_to_erase.
 */
node* list_erase(node* head, int value_to_erase) {
  node* result = NULL;
  node* tail = NULL;

  while (head != NULL) {
    if (head->val != value_to_erase) {
      node* newnode = malloc(sizeof(node));
      newnode->val = head->val;
      newnode->next = NULL;

      if (result == NULL) {
        result = newnode;
        tail = newnode;
      } else {
        tail->next = newnode;
        tail = newnode;
      }
    }
    head = head->next;
  }
  return result;
}

/**
 * Cancella dalla lista tutti i nodi che contengono il valore value_to_erase.
 */
node* list_erase2(node* head, int val_to_erase) {
  node* l = head;
  node* prev = NULL;

  while (l != NULL) {
    if (l->val == val_to_erase) {  // Se il valore del nodo corrente è quello da eliminare
      node* temp = l;              // Salva il nodo da eliminare
      if (prev == NULL) {          // Se il nodo da eliminare è la testa della lista
        head = l->next;            // Aggiorna la testa
        l = head;                  // Sposta il puntatore corrente alla nuova testa
      } else {
        prev->next = l->next;  // Salta il nodo corrente
        l = l->next;           // Avanza al prossimo nodo
      }
      free(temp);  // Libera la memoria del nodo eliminato
    } else {
      prev = l;     // Aggiorna il precedente
      l = l->next;  // Avanza al prossimo nodo
    }
  }
  return head;  // Ritorna la nuova testa della lista
}

int main() {
  int arr1[] = {1, 3, 4, 7, 5, 3, 2};
  node* l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(int));

  printf("Lista iniziale: ");
  printlist(l1);
  printf("Lista dopo erase: ");
  printlist(list_erase(l1, 3));

  int arr2[] = {1, 3, 4, 7, 5, 3, 2};
  node* l2 = ArrayToList(arr2, sizeof(arr2) / sizeof(int));
  printf("\nLista iniziale: ");
  printlist(l2);
  printf("Lista dopo erase2: ");
  printlist(list_erase2(l2, 3));
}