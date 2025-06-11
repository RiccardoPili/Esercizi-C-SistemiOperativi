#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
  char *str;
  struct _node *next;
} node;

// ------------- metodi ausiliari --------------------
void printlist(node *l) {
  while (l != NULL) {
    printf("%s -> ", l->str);
    l = l->next;
  }
  printf("NULL\n");
}

node *Cons(char *x, node *xs) {
  node *newnode = malloc(sizeof(node));
  newnode->str = strdup(x);  // Duplicate string to avoid pointer issues
  newnode->next = xs;
  return newnode;
}

node *ArrayToList(char *A[], int n) {
  node *l = NULL;
  for (int i = n - 1; i >= 0; i--) {
    l = Cons(A[i], l);
  }
  return l;
}

/**
 * Restituisce la stringa ottenuta concatenando le stringhe della
 * lista puntata da head, separate da uno spazio
 *
 * esempio:
 * head -> "ciao" -> "come" -> "stai?"
 * res = "ciao come stai?"
 */
char *list_to_string(node *head) {
  if (head == NULL)
    return NULL;

  node *temp = head;
  unsigned int total_len = 0;
  int nof_words = 0;
  while (temp != NULL) {
    total_len += strlen(temp->str);
    temp = temp->next;
    nof_words++;
  }
  char *res = malloc(total_len + nof_words);  // per tenere anche il posto per spazi e \0

  temp = head;
  char *p = res;
  while (temp != NULL) {
    int len = strlen(temp->str);
    memcpy(p, temp->str, len);
    p += len;
    if (temp->next != NULL) {  // se non è l'ultima stringa
      *p = ' ';
      p++;
    }
    temp = temp->next;
  }
  *p = '\0';

  return res;
}

int main() {
  char *arr[] = {"ciao", "come", "stai?"};
  int n = sizeof(arr) / sizeof(arr[0]);
  node *list = ArrayToList(arr, n);

  printf("Lista: ");
  printlist(list);

  char *result = list_to_string(list);
  printf("Stringa concatenata: \"%s\"\n", result);
}
