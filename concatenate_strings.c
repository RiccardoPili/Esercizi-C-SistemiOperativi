#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concatenate_strings(char ** v, int n){
    if(v == NULL || n <= 0) return NULL;

    int total_lenght = 0;
    for(int i = 0; i < n; i++){
        total_lenght += strlen(v[i]);
    }

    char * result = malloc(total_lenght + 1);

    int j = 0;
    for(int i = 0; i < n; i++){
        for(int k=0; v[i][k] != '\0'; k++){
            result[j] = v[i][k];
            j++;
        }
    }

    result[j] = '\0';

    return result;
}

int main(){
    char * v[] = {"Ciao", ", come", " ", "stai?"};
    int n = sizeof(v) / sizeof(v[0]);

    char * concat = concatenate_strings(v, n);
    printf("%s\n", concat);
}