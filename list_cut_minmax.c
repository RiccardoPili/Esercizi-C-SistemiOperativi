#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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


// ------------- ESERCIZIO ---------------------------

node * list_cut_minmax(node * ls){
    int min = INT_MAX;
    int max = INT_MIN;
    node * l = ls;

    // 1. trovare min e max
    while(l != NULL){
        if (l->val < min)
            min = l->val;
        if (l->val > max)
            max = l->val;
        l = l->next;
    }
    // printf("min %d, max %d\n", min, max);
    
    // 2. scorrere la lista cercando min e cambia puntatore a next->next
    node * prev_min = NULL;
    node * l1 = ls;
    while(l1 != NULL){
        if(l1->val == min) 
            prev_min->next = l1->next;
        
        prev_min = l1;
        l1 = l1->next;
    }

    // 2. scorrere la lista cercando max e cambia puntatore a next->next
    node * prev_max = NULL;
    node * l2 = ls;
    while(l2 != NULL){
        if(l2->val == max)
            prev_max->next = l2->next;

        prev_max = l2;
        l2 = l2->next;
    }

    return ls;
}

int main(){
    int a[] = {5, 4, 2, 8, 3, 7, 3};
    node * l = ArrayToList(a, sizeof(a) / sizeof(int));
    
    printf("Lista prima: ");
    printlist(l);

    printf("Lista dopo: ");
    printlist(list_cut_minmax(l));
}