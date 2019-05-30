/*
    Scrivere un programma che dato
         un nome di un file
         comando da eseguire completo di argomenti
         eventuali @

    Il programma deve leggere il file riga per riga
    Eseguire il comando specificato nell'input per ogni riga
    Inoltre per ogni @ aggiungere al comando specificato il contenuto della riga corrente

    Esempio:
    $ cat example.txt
    file1
    file2
    file3

    $ ./file_exec example.txt cat @
    contenuto dei file..
*/


#include <stdio.h> // printf()
#include <unistd.h> // per getuid()/getgid()/ecc...
#include <string.h>
#include <stdlib.h>

void viewArrayOfPointers(char **a){
    for (char **test = a; *test; ++test){
        printf("Value of argvcmd: %s\n", *test);
    }
}

int main (int argc, char **argv){
    if (argc < 2) {
        fprintf(stderr, "Fornire il nome del file\n");
        return 1;
    } else if (argc < 3){
        fprintf(stderr, "Fornire il comando da eseguire\n");
        return 2;
    } 
    //gettiamo il nome del file
    char *nomeFile = malloc((strlen(argv[1])+1)*sizeof(char));
    strcpy(nomeFile, argv[1]);
    char *cmd = malloc((strlen(argv[2])+1)*sizeof(char));
    strcpy(cmd, argv[2]);

    //devo salvare di nuovo il comando + i suoi argomenti
    char **argvcmd = argv + 2;
    //viewArrayOfPointers(argvcmd);
    
    //devo leggere il file riga per riga
    //apro il file
    FILE *file = fopen(nomeFile, "r");
    if (!file){
        fprintf(stderr, "Errore nell'apertura in uno dei file!\n");
        return 2;
    }
    //meglio usare fgetc e copiare char per char
    //fin quando non si arriva a '\n' 
    char *testo = malloc(2*sizeof(char));
    //char **contenutoRighe = malloc(2*sizeof(char));
    //int numeroRighe = 0; //+1 logicamente
    for (int i = 0; !feof(file); ++i){
        testo[i] = fgetc(file);
        testo = (char *)realloc(testo, (i+1+1)*sizeof(char));
        if (testo[i]=='\n'){
            //strcpy(contenutoRighe[numeroRighe], testo);
            fprintf(stdout, "stringa corrente: %s\n", testo);
            //++numeroRighe;
            //contenutoRighe = realloc(contenutoRighe, (numeroRighe+1)*sizeof(char));
            //contenutoRighe[numeroRighe+1] = realloc (contenutoRighe, (numeroRighe+1)*sizeof(char)); 
            i=-1;
        }
    }
    free(testo);
    fclose(file);
    

    return 0;
}