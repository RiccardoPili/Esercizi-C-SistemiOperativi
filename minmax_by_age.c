#include <stdio.h>
#include <stdlib.h>

typedef struct record{
    char * name;
    unsigned int age;
} record;


record ** minmax_by_age(record vec[], unsigned int len){
    record ** result;
    int i;

    result = malloc(2*sizeof(*result));
    result[0] = result[1] = vec;

    for(i = 1; i < len; i++){
        if(vec[i].age < result[0]->age){
            result[0] = vec + i; 
        }
        if(vec[i].age > result[1]->age){
            result[1] = vec + i;
        }
    }

    return result;
}


int main(){
    struct record v[] = {{"Adele", 20}, {"Bianca", 12}, {"Carlo", 14}, {"Marco", 18}, {"Luca", 24}};

    record ** min_max_v;
    min_max_v = minmax_by_age(v, 5);

    printf("Persona con età minima: %s, %u anni\n", min_max_v[0]->name, min_max_v[0]->age);
    printf("Persona con età massima: %s, %u anni\n", min_max_v[1]->name, min_max_v[1]->age);

    free(min_max_v);
}
