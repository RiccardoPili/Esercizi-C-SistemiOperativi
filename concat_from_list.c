#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char * s;
    struct _node * next;
} node;

// ------------- metodi ausiliari --------------------
void printlist(node * l) {
    while (l != NULL) {
        printf("%s ", l->s);
        l = l->next;
    }
    printf("\n");
}

node * Cons(char * x, node * xs) {
    node * newnode = malloc(sizeof(node));
    newnode->s = strdup(x); // Duplicate string to avoid pointer issues
    newnode->next = xs;
    return newnode;
}

node * ArrayToList(char * A[], int n) {
    node * l = NULL;
    for (int i = n - 1; i >= 0; i--) {
        l = Cons(A[i], l);
    }
    return l;
}

// ------------- ESERCIZIO ---------------------------

char * concat_from_list(node * head){
    char * result;
    int res_len;
    node * p;

    // Calcola la lunghezza e alloca lo spazio per la stringa result
    for(p = head, res_len = 0; p != NULL; p = p->next){
        res_len += strlen(p->s) + 1;
    }
    result = malloc(res_len);

    // Usa strcat per copiare la stringa nel risultato result, aggiungendo uno spazio alla fine
    for(p = head; p != NULL; p = p->next){
        strcat(result, p->s);
        strcat(result, " ");
    }
    result[res_len - 1] = '\0'; // fine stringa

    return result;
}


int main() {
    char * arr1[] = {"Stanno", "tutti", "molto bene"};
    node * l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(char *));

    printf("Lista l1: ");
    printlist(l1);

    char * str_result = concat_from_list(l1);
    printf("Stringa: %s\n", str_result);
    return 0;
}