#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int value;
    struct _node * next;
} node;

/*
    Riceve in input un array di liste terminate da NULL
    Per ogni elemento dell'array elimina tutti i nodi che sono minori o uguali 
    a qualche elemento che li precede
*/
void vec_list_cut_leq(node ** vec_head){
    node * p;
    node * p_next;
    node * aux;
    node * head;

    for(; (head = *vec_head) != NULL; vec_head++){
        p = head;
        for(p_next = p->next; p_next != NULL; p_next = p->next){
            if(p->value <= p_next->value){
                aux = p_next;
                p->next = p_next->next;
                free(aux);
            } else {
                p = p_next;
            }
        }
    }
}


// -------------- MAIN e FUNZIONI AUSILIARIE ------------------
// Helper function to create a new node
node * create_node(int value) {
    node * new_node = (node *)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Helper function to print a list
void print_list(node * head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

// Helper function to free a list
void free_list(node * head) {
    node * temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create test lists
    node * list1 = create_node(5);
    list1->next = create_node(3);
    list1->next->next = create_node(8);
    list1->next->next->next = create_node(2);

    node * list2 = create_node(10);
    list2->next = create_node(7);
    list2->next->next = create_node(12);

    node * list3 = create_node(1);
    list3->next = create_node(2);
    list3->next->next = create_node(3);

    // Create an array of lists
    node * vec[] = {list1, list2, list3, NULL};

    // Print original lists
    printf("Original lists:\n");
    for (int i = 0; vec[i] != NULL; i++) {
        printf("List %d: ", i + 1);
        print_list(vec[i]);
    }

    // Apply the function
    vec_list_cut_leq(vec);

    // Print modified lists
    printf("\nModified lists:\n");
    for (int i = 0; vec[i] != NULL; i++) {
        printf("List %d: ", i + 1);
        print_list(vec[i]);
    }

    // Free memory
    for (int i = 0; vec[i] != NULL; i++) {
        free_list(vec[i]);
    }

    return 0;
}