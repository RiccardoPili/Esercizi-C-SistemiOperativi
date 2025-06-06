#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int *vec;
  unsigned int len;
  struct _node *next;
} node;

/**
 * Stampa i vettori contenuti in una lista di nodi.
 * Ogni nodo contiene un vettore di interi e la sua lunghezza.
 */
void print_list(node *head) {
  node *curr = head;
  unsigned int i;

  while (curr != NULL) {
    for (i = 0; i < curr->len; i++) {
      printf("%d ", curr->vec[i]);
    }
    printf("\n");
    curr = curr->next;
  }
}

int main() {
  // Create nodes
  node *node1 = (node *)malloc(sizeof(node));
  node *node2 = (node *)malloc(sizeof(node));
  node *node3 = (node *)malloc(sizeof(node));

  // Initialize node1
  int vec1[] = {1, 2, 3};
  node1->vec = vec1;
  node1->len = 3;
  node1->next = node2;

  // Initialize node2
  int vec2[] = {4, 5};
  node2->vec = vec2;
  node2->len = 2;
  node2->next = node3;

  // Initialize node3
  int vec3[] = {6, 7, 8, 9};
  node3->vec = vec3;
  node3->len = 4;
  node3->next = NULL;

  // Print the list
  print_list(node1);

  // Free allocated memory
  free(node1);
  free(node2);
  free(node3);

  return 0;
}