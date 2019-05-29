#include <stdio.h>
#include <stdlib.h>

/*
    Senza nessun argomento aggiuntivo si comporta nella stessa maniera di esempio-ambiente
    QUando viene aggiunto un argomento, stampa l'ambiente di quell'argomento
*/

int main (int argc, char **argv, char **envp){
    if (argc <= 1){
        while (*envp){
            printf("%s\n", *envp);
            ++envp;
        }
    } else {
        printf("%s=%s\n", argv[1], getenv(argv[1]));
    }
    return 0;
}