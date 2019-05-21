#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Il programma simula il comando cmp di unix
*/

int main (int argc, char **argv){
    if (argc < 2){
        fprintf(stderr, "Fornire i nomi dei file \n");
        return 1;
    }
    if (argc != 3){
        fprintf(stderr, "Si possono inserire solamente due file");
        return 2;
    }
    
    char *nomePrimoFile = argv[1];
    char *nomeSecondoFile = argv[2];

    FILE *file1 = fopen(nomePrimoFile, "r");
    if (!file1){
        fprintf(stderr, "Errore nell'apertura del primo file!\n");
        return 3;
    }
    FILE *file2 = fopen(nomeSecondoFile, "r");
    if (!file2){
        fprintf(stderr, "Errore nell'apertura del secondo file!\n");
        return 4;
    }
    char *text = malloc()
    while (!feof(file1) && !feof(file2)){
        fgets()
    }


    return 0;
}