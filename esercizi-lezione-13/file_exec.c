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
int checkIfThereAreAnyAt(char **a){
    for (char **test = a; *test; ++test){
        //printf("Sei al controllo:\n\t%s\n", *test);
        if (strcmp(*test, "@")==0){
            //printf("\tIF\n");
            return 1;
        }
    }
    return 0;
}
//PRESUPPONE CHE CI SIA LA @ NELLA MATRICE
int positionAt(char **a){
    int i=0;
    for (char **test = a; *test; ++test){
        if (strcmp(*test, "@")==0){
            return i;
        }
        i++;
    }
    return -1;
}

int countHowManyRows (char **ptr){
    int c = 0;
    for (char **i = ptr; *i; ++i){
        ++c;
    }
    return c;
}

//caso in cui devo sostituire @ con il testo
void modifyArgvcmd(char **argvcmd, char *daConcatenare){
    //void *ptr = (char)argvcmd[1][0];
    //printf("%s\n", argvcmd[1]);
    strcpy(argvcmd[positionAt(argvcmd)], daConcatenare);
    
}
//caso in cui devo aggiungere una riga alla matrice
void addArgvcmd(char **argvcmd, char *daAggiungere){
    //void *ptr = (char)argvcmd[1][0];
    //printf("%s\n", argvcmd[1]);
    int c = countHowManyRows(argvcmd);
    argvcmd[c] = malloc(strlen(daAggiungere)*sizeof(char));
    printf("valore delle righe: %d", c);
    printf("valore: %s\n", argvcmd[c-1]);
    strcpy(argvcmd[c], daAggiungere);
    argvcmd[c+1] = NULL; 
    
}

void copyMatrix (char **destinazione, char **sorgente){
    char **b = destinazione;
    printf("-----\n");
    for (char **a = sorgente; *a; ++a){
        *b = malloc((strlen(*a)*sizeof(char)));
        strcpy(*b, *a);
        ++b;
    }
    //punto all'ultimo elemento
    //gli alloco lo spazio per inserire la parola ciao
    *b = NULL;
    // *b = malloc((strlen("ciao")+1)*sizeof(char));
    // strcpy(*b, "ciao");
    // ++b;
    // *b = NULL;
}

void addAWord (char **destinazione, char *source){
    char **b = destinazione;
    while (*b){
        ++b;
    }
    *b = malloc((strlen(source)+1)*sizeof(char));
    strcpy(*b, source);
    ++b;
    *b=NULL;
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
    char **temp = argv + 2;

    // DEVO SALVARE TUTTO ARGV
    // DA QUALCHE PARTE PERCHE
    // PER AGGIUNGERE UN ELEMENTO
    // SONO OBBLIGATO A POTER ACCEDERE
    // AL PUNTATORE

    viewArrayOfPointers(temp);
    //+2 perche' aggiungo un elemento e uno deve essere il null
    char **argvcmd = malloc((countHowManyRows(temp)+2)*sizeof(char*));
    copyMatrix(argvcmd, temp);
    addAWord(argv, "ciao");
    //per ogni elemento riga di argvcmd
    // char **b = argvcmd;
    // printf("-----\n");
    // for (char **a = temp; *a; ++a){
    //     *b = malloc((strlen(*a)*sizeof(char)));
    //     strcpy(*b, *a);
    //     ++b;
    // }
    // *b = malloc((strlen("ciao")*sizeof(char)));
    // strcpy(*b, "ciao");
    // ++b;
    // *b = NULL;
    
    viewArrayOfPointers(argvcmd);
    printf("-----\n");

    //checkIfThereAreAny@
    if (checkIfThereAreAnyAt(argvcmd)){
        modifyArgvcmd(argvcmd, "ciao");
        //printf("YES \n");
    } else {
        addArgvcmd(argvcmd, "ciao");
    }
    printf("-----\n");
    printf("Dopo aver modificato:\n");
    viewArrayOfPointers(argvcmd);

    //devo leggere il file riga per riga
    //apro il file
    FILE *file = fopen(nomeFile, "r");
    if (!file){
        fprintf(stderr, "Errore nell'apertura in uno dei file!\n");
        return 2;
    }

    fprintf(stdout, "-------\n");
    //meglio usare fgetc e copiare char per char
    //fin quando non si arriva a '\n' 
    char *testo = malloc(2*sizeof(char));
    //char **contenutoRighe = malloc(2*sizeof(char));
    //int numeroRighe = 0; //+1 logicamente
    FILE *fileInterno;
    for (int i = 0; !feof(file); ++i){
        testo[i] = fgetc(file);
        testo = (char *)realloc(testo, (i+1+1)*sizeof(char));
        if (testo[i]=='\n'){
            //strcpy(contenutoRighe[numeroRighe], testo);
            fprintf(stdout, "stringa corrente: %s\n", testo);
            
            
            i=-1;
        }
    }
    free(testo);
    fclose(file);
    

    return 0;
}