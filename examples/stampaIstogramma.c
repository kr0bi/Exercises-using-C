#include <stdio.h>
/*
    Scrivere un programma C che stampi un istogramma
    orizzontale (utilizzando il carattere ’-’) raffigurante le
    lunghezze delle parole (delimitate da whitespace characters)
    immesse sullo standard input (parola per parola).
*/
int main(){
    int c = getchar();
    int isPrecedentCharAWhitespace = 0;  
    printf("\n");
    while (c!=EOF){
       if (c!='\n' && c!='\t' && c!=' '){
           isPrecedentCharAWhitespace = 0;
            printf("-");
        }
        if (isPrecedentCharAWhitespace && (c=='\n' || c=='\t' || c==' ')){
            isPrecedentCharAWhitespace = 1;
        } else if (c=='\n' || c=='\t' || c==' '){
            isPrecedentCharAWhitespace = 1;
            printf("\n");
        }
        c = getchar();
    }
    printf("\n");
    return 0;
}