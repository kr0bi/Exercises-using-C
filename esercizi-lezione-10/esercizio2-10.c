#include <stdio.h>
#define LENGTH 4
/*
    deve riempire la stringa puntata da line
    con caratteri letti dallo standard input
    fino a che non viene letto:
        -EOF
        -\n
        -il numero di caratteri e' uguale a len
    Ci si assicuri che la stringa venga terminata
    correttamente. significa che nella posizione 
    La funzione restituisce il numero di caratteri
    letti oppure -1 se nessun carattere e' stato letto
    ed e' stata trovata subito EOF
*/
int readline (char *line, unsigned len);

int main (int argc, char **argv){
    //line viene riempita dallo standard input
    char str[LENGTH];
    printf("Numero di caratteri letti: %d\n", readline(str, LENGTH));
    
    printf("Caratteri: ");
    for (char *p=str; *p; ++p){
        printf("'%c' ", *p);
    }
    printf("\n");
    return 0;
}

int readline (char *line, unsigned len){
    int numberOfCharRead=0;
    char val=getchar();
    if (val==EOF){
        numberOfCharRead=-1;
    }
    while (val!='\n' && val!=EOF && len>numberOfCharRead){
        line[numberOfCharRead]=val;
        val = getchar();
        ++numberOfCharRead;
    }
    line[numberOfCharRead]='\0';
    return numberOfCharRead;
}