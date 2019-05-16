#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc < 2){
        fprintf(stderr, "Fornire il nome del file \n");
        return 1;
    }
    //il numero di file inseriti e' il numero di input che vengono messi
    int numberOfFiles = argc;
    //l'idea e' di farne uno per volta
    //calcolo la length del primo file
    char *nomePrimoFile = argv[1];
    
    
    char *nomi_dei_file = malloc(strlen(nomePrimoFile)*sizeof(char));
    //mi sono dimenticato di impostare i nomi dei file



    //ora devo aprire uno per uno ogni file, copiare il suo contenuto
    //all'interno di una stringa
    //e ricordarmi di spostarmi alla fine della stringa per aggiungerci
    //il file successivo
    int n = 0, i = 1;
    //devo allocare dinamicamente lo spazio per la stringa
    char *testo = malloc(10*sizeof(char));
    printf("%s", "bel meme");

    while (n!=argc){
        nomi_dei_file = realloc(nomi_dei_file, strlen(argv[i+n])*sizeof(char));
        nomi_dei_file = argv[i+n];

        FILE *file = fopen(nomi_dei_file + n, "r");
        if (!file){
            fprintf(stderr, "Errore nell'apertura del file!\n");
        return 2;
        }
        //inizialmente puo' essere lunga 10, ma poi devo allungarla man
        //mano che leggo l'input
        while(!feof(file)){
            //ora devo copiare tutto il contenuto all'interno di una
            //stringa
            testo = testo + fgetc(file); //non ho idea se sta cosa funziona
            testo = realloc(testo, 1+sizeof(char));
        }
        //ricordarsi di chiudere sempre il file aperto
        fclose(file);
        n++;
    }    
    free(nomi_dei_file);
    //stampare l'output
    printf("%s", testo);
    free(testo);
    return 0;
}