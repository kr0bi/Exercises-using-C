#include <stdio.h>
/*
    Funzione che sostituisce, nella stringa puntata da str, ogni occorrenza di una
    lettera latina minuscola all’inizio di una parola con la corrispondente
    maiuscola.
*/
void capitalize (char *str);

int main (){
    char str[] = "ciAo soNo DaNIele e questa e' una prova di caRATTeri";
    printf("\n%s --->", str);
    capitalize(str);
    printf(" %s\n\n", str);
    return 0;
}
/*
    Devo iterare tutto il contenuto di una stringa fino al carattere \0
    Se il char e' una lettera minuscola, la devo sostituire con la sua maiuscola
    Si puo' usare il codice ASCII ed inviduare tutti i char minuscoli e convertirli, sommando il char
    della distanza tra la minuscola e la sua maiuscola
*/
void capitalize (char *str){
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]>=97 && str[i]<=122){
            str[i]=str[i]-32;
        }
    }
}