#include <stdio.h>
/*
    Scrivere un programma C che conti il numero di spazi, tab e
    newline (whitespace characters) presenti nei caratteri immessi
    sullo standard input.
*/

int is_whitespace(char val);

int main(){
    int cont=0;
    int c = getchar();
    while (c != EOF){
        if (is_whitespace(c)){
            ++cont;
        }
        c = getchar();
    }
    printf("Il numero di whitespace all'interno della stringa e' %d", cont);
    return 0;
}
int is_whitespace(char val){
    int res=0;
    if (val == ' ' || val == '\n' || val == '\t'){
        res = 1;
    }
    return res;
}