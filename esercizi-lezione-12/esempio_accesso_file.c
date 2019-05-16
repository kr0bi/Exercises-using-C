#include <stdio.h>
int main (int argc, char **argv){
    if (argc < 2){
        fprintf(stderr, "Fornire il nome del file \n");
        return 1;
    }
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file){
        fprintf(stderr, "Errore nell'apertura del file!\n");
        return 2;
    }
    int n=0, sum=0;
    while (fscanf(file, "%d", &n) == 1){
        sum += n;
    }
    if (!feof(file)){
        fprintf(stderr, "Il file non conteneva solo numeri.\n");
        return 3;
    }
    printf("Somma dei numeri contenuti: %d\n", sum);
    return 0;
}