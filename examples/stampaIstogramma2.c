#include <stdio.h>
/*
    Scrivere un programma C che stampi un istogramma
    orizzontale (utilizzando il carattere ’-’) raffigurante le
    lunghezze delle parole (delimitate da whitespace characters)
    immesse sullo standard input (parola per parola).
*/
int is_whitespace(char val);

int main(){
    int c = getchar();
    int isPrecedentCharAWhitespace = 0;  
    int currentTrattiniNumber = 0;
    int numberOfWords = 0;
    printf("\n");
    while (c!=EOF){
       if (c!='\n' && c!='\t' && c!=' '){
           isPrecedentCharAWhitespace = 0;
           ++currentTrattiniNumber;
           printf("-");
        }
        if (isPrecedentCharAWhitespace && (is_whitespace(c))){
            isPrecedentCharAWhitespace = 1;
        } else if (is_whitespace(c)){
            isPrecedentCharAWhitespace = 1;
            ++numberOfWords;
            printf("\n");
        }
        c = getchar();
    }
    printf("\n");
    return 0;
}
int is_whitespace(char val){
    int res=0;
    if (val == ' ' || val == '\n' || val == '\t'){
        res = 1;
    }
    return res;
}