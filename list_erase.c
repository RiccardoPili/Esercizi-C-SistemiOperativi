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

node * list_erase(node * head, int value_to_erase){
    node * result = NULL;
    node * tail = NULL;

    while(head != NULL){
        if(head->val != value_to_erase){
            node * newnode = malloc(sizeof(node));
            newnode->val = head->val;
            newnode->next = NULL;

            if(result == NULL){
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

int main(){
    int arr1[] = {1, 3, 4, 7, 5, 3, 2};
    node * l1 = ArrayToList(arr1, sizeof(arr1) / sizeof(int));

    printf("Lista iniziale: ");
    printlist(l1);

    printf("Lista dopo erase: ");
    printlist(list_erase(l1, 3));
}