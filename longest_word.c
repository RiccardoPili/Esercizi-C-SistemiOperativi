#include <stdio.h>
#include <stdlib.h>

char * longest_word(char * str){
    int max_length = 0;
    int current_length = 0;
    char * temp = str;
    char * longest = NULL;

    if(str == NULL) return NULL;

    while(*str) {
        if(*str != ' ') {
            if(current_length == 0) temp = str;
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                longest = temp;
            }
            current_length = 0;
        }
        str++;
    }

    if (current_length > max_length) {
        max_length = current_length;
        longest = temp;
    }

    printf("current length: %d\n", current_length);
    printf("max lenght: %d\n", max_length);

    char * result = malloc((max_length - 1));
    for (int i = 0; i < max_length; i++) {
        result[i] = longest[i];
    }
    result[max_length] = '\0';

    return result;
}

int main()
{
    printf("The longest word is: %s\n", longest_word("Stringa di prova sdasd"));
    return 0;
}