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
    
    //non ho idea se quel +1 e' necessario
    // il +1 e' necessario per il carattere di terminazione
    char *nomi_dei_file = (char *)malloc((strlen(nomePrimoFile)+1)*sizeof(char));
    //mi sono dimenticato di impostare i nomi dei file

    //ora devo aprire uno per uno ogni file, copiare il suo contenuto
    //all'interno di una stringa
    //e ricordarmi di spostarmi alla fine della stringa per aggiungerci
    //il file successivo
    int n = 0, i =1;
    int contatore=0;
    //devo allocare dinamicamente lo spazio per la stringa
    char *testo = (char *)malloc(10*sizeof(char));
    //inizialmente gli do 10 cosi' a caso
    while (i!=argc){    
        nomi_dei_file = (char *)realloc(nomi_dei_file, (strlen(argv[i])+1024)*sizeof(char));
        strcpy(nomi_dei_file + n, argv[i]);
        FILE *file = fopen(nomi_dei_file + n, "r");
        if (!file){
            fprintf(stderr, "Errore nell'apertura in uno dei file!\n");
        return 2;
        }
        //inizialmente puo' essere lunga 10, ma poi devo allungarla man
        //mano che leggo l'input
        //printf("%s\n", "sono qui");
        while(!feof(file)){
            //ora devo copiare tutto il contenuto all'interno di una
            //stringas
            testo[contatore] = fgetc(file);
            testo = (char *)realloc(testo, (strlen(testo)+1)*sizeof(char));
            ++contatore;
        }
        //ricordarsi di chiudere sempre il file aperto
        fclose(file);
        n++;
        i++;
    }    
    free(nomi_dei_file);
    //stampare l'output
    testo[contatore] = 0;
    printf("%s", testo);
    free(testo);
    return 0;
}