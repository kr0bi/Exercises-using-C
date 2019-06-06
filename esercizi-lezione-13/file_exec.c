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
        if (strcmp(*test, "@")==0){
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
    strcpy(argvcmd[positionAt(argvcmd)], daConcatenare);
    
}
//caso in cui devo aggiungere una riga alla matrice
void addArgvcmd(char **argvcmd, char *daAggiungere){
    int c = countHowManyRows(argvcmd);
    argvcmd[c] = malloc(strlen(daAggiungere)*sizeof(char));
    strcpy(argvcmd[c], daAggiungere);
    argvcmd[c+1] = NULL; 
    
}

void copyMatrix (char **destinazione, char **sorgente){
    char **b = destinazione;
    for (char **a = sorgente; *a; ++a){
        *b = malloc((strlen(*a)*sizeof(char)));
        strcpy(*b, *a);
        ++b;
    }
    *b = NULL;
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

void copy (char *destination, char *source){
    strcpy(destination, source);
    destination[(strlen(source)-1)]=0;
}

void clearTesto(char *testo){
    int length = strlen(testo);
    for (int i=0; i<length; ++i){
        testo[i] = 0;
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
    char **temp = argv + 2;

    //+2 perche' aggiungo un elemento e uno deve essere il null
    char **argvcmd = malloc((countHowManyRows(temp)+2)*sizeof(char*));
    copyMatrix(argvcmd, temp);

    //devo leggere il file riga per riga
    //apro il file
    FILE *file = fopen(nomeFile, "r");
    if (!file){
        fprintf(stderr, "Errore nell'apertura in uno dei file!\n");
        return 2;
    }

    char *testo = malloc(2*sizeof(char));
    FILE *fileInterno;

    //devo salvare il current argvcmd
    char **current_argvcmd = malloc((countHowManyRows(argvcmd)+2)*sizeof(char*));
    copyMatrix(current_argvcmd, argvcmd);

    //variabile senza il \n
    char *real_testo;

    for (int i = 0; !feof(file); ++i){
        testo[i] = fgetc(file);
        testo = (char *)realloc(testo, (i+1+1)*sizeof(char));
        if (testo[i]=='\n'){
            
            //devo copiare il testo fino a prima
            //dell'invio
            real_testo = malloc(strlen(testo)*sizeof(char));
            copy(real_testo, testo);            
            
            //controllo se ci sono @, in tal caso sostituisco @ con la riga del file
            if (checkIfThereAreAnyAt(argvcmd)){
                modifyArgvcmd(argvcmd, real_testo);
            } 
            //inizio il fork
            pid_t pid = fork();
            switch (pid){
                case -1:
                    perror("fork() failed");
                    return -1;
                case 0:
                    //printf("cmd: %s\n", cmd);
                    //viewArrayOfPointers(argvcmd);
                    execvp(cmd, argvcmd);
                    perror("exec failed");
                    return 1;
                default:
                    wait(NULL);
            }
            //ricopio da capo gli argomenti iniziali
            copyMatrix(argvcmd, current_argvcmd);
            //azzero quello che ho scritto finora
            clearTesto(testo);
            i=-1;
        }
    }
    free(testo);
    fclose(file);
    
    return 0;
}