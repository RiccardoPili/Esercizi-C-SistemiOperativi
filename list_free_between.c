#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int val;
    struct _node * next;
} node;

// ------------- metodi ausiliari --------------------
void printlist(node * l) {
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

node * Cons(int x, node * xs) {
    node * newnode = malloc(sizeof(node));
    newnode->val = x;
    newnode->next = xs;
    return newnode;
}

node * ArrayToList(int A[], int n){
    node * l = NULL;
    for(int i=n-1; i>=0; i--){
        l = Cons(A[i], l);
    }
    return l;
}


// -------------- ESERCIZIO --------------------------

node * free_between(node * head, int a, int b){
    node * l1 = head; 
    node * prev = NULL;

    while(l1 != NULL){
        if(l1->val >= a && l1->val <= b){ // Caso: nodo da eliminare
            node * temp = l1;
            if(prev == NULL){ 
                head = l1->next; // se il primo nodo è da eliminare
            } else {
                prev->next = l1->next; // altri nodi da eliminare
            }
            l1 = l1->next;
            free(temp);
        }
        else { // Caso: nodo da mantenere
            prev = l1;
            l1 = l1->next;
        }
    }

    return head;
}

int main(){
    int arr1[] = {1, 3, 4, 7, 5, 3, 2, 10, 5, 6, 7, 12, 2, 8};
    node * l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(int));

    printf("Lista iniziale: ");
    printlist(l1);

    printf("Lista dopo free_between(3, 6): ");
    printlist(free_between(l1, 3, 6));
}