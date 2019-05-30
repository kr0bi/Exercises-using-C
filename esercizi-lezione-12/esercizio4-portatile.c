#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Il programma simula il comando cmp di unix
*/

int main (int argc, char **argv){
    //verifico che ci sia almeno un file
    if (argc < 2){
        fprintf(stderr, "Fornire i nomi dei file \n");
        return 1;
    }
    //verifico che ci siano esattamente due file
    if (argc != 3){
        fprintf(stderr, "Si possono inserire solamente due file\n");
        return 2;
    }
    //inizializzo i nomi dei file
    
    char *nomePrimoFile = argv[1];
    char *nomeSecondoFile = argv[2];

    //provo ad aprire i file
    //altrimenti termino
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
    //devo momentaneamente allocare la dimensione della prima riga
    //quindi leggere finche' non arrivo alla fine riga o a un EOF
    int size = 1024;
    char *testo1 = malloc(size*sizeof(char));
    
    //momentaneamente alloco la dimensione per il testo 2
    char *testo2 = malloc(size*sizeof(char));
    
    //inizio effettivo programma
    //inizializzo il numero riga
    int numberOfRowRead = 1;
    while (!feof(file1) && !feof(file2)){
        //non posso sapere a priori la lunghezza, quindi alloco un buffer statico 
        //in caso di errore, lo raddoppio
        fgets(testo1, size, file1);
        //  DEVO VERIFICARE CHE L'ULTIMO CARATTERE SIA UN NEW LINE SE
        //  NON LO E', DEVE ESSERE RADDOPIATA LA SIZE E FATTO UN MALLOC
        //il carattere prima del terminatore e' un \n
        //lezione 11 buffer statico
        fgets(testo2, size, file2);
        if (testo1[strlen(testo1)-1]!='\n' || testo2[strlen(testo2)-1]!='\n'){
            size = size*2;
            realloc(testo1, size);
            realloc(testo2, size);
        }
        if (strcmp(testo1, testo2)!=0){
            break;
        }
        ++numberOfRowRead;
    }
    //inserisco il carattere di terminazione
    testo1[strlen(testo1)]=0;
    testo2[strlen(testo2)]=0;
    fclose(file1);
    fclose(file2);
    fprintf(stdout, "Le due righe che differiscono:\n\t%s\n\t%s", testo1, testo2);
    free(testo1);
    free(testo2);
    
    return 0;
}