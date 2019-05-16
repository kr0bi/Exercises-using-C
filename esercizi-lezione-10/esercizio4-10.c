#include <stdio.h>
#include <string.h>
#define LENGTH 5
/*
    Scrivere un programma che legga una sequenza di numeri dallo standard
    input, e:
    - Se l’utente ha passato l’opzione -r sulla riga di comando,
        stampi i numeri in ordine inverso.
    - Se l’utente ha passato l’opzione -s, stampi i numeri ordinati in
        senso crescente.
    - Se l’utente ha passato l’opzione -S, stampi i numeri ordinati in
        senso decrescente.
    - Se l’utente non ha passato alcuna opzione, stampare un
        messaggio di errore e non fare nulla (ancora prima di leggere
        alcunché).
*/
void reverse(int *values, int size);
void sort (int *values, int size);
void desort (int *values, int size);
void swap (int *a, int *b);
void viewArray (int *a, int size);

int main (int argc, char **argv){
    if (argc == 1){
        printf("ERRORE, non e' stato inserito alcun input\n");
        return -1;
    }
    //inserimento input
    int values[LENGTH];
    int n = 0;
    int value = 0;
    while(n < LENGTH && scanf("%d", &value) == 1) {
        values[n] = value;
        ++n;
    }
    printf("Numeri inseriti: ");
    for(int i = 0; i < LENGTH; ++i) {
        printf("%d ", values[i]);
    }
    putchar('\n');

    //sezione che esegue quello che viene richiesto
    for (int i=1; i<argc; ++i){
        if (argc >= 2 && strcmp(argv[i], "-r")==0){
            printf("-r\n");
            reverse(values, LENGTH);
            viewArray(values, LENGTH);
        }
        else if (argc >= 2 && strcmp(argv[i], "-s")==0){
            printf("-s\n");
            sort(values, LENGTH);
            viewArray(values, LENGTH);
        }
        else if (argc >= 2 && strcmp(argv[i], "-S")==0){
            printf("-S\n");
            desort(values, LENGTH);
            viewArray(values, LENGTH);
        } else {
            printf("L'opzione non e' stata aggiunta\n");
        }
    }
    return 0;
}

void reverse (int *values, int size){
    for (int i=0; i<size/2; i++){
        swap(&values[i], &values[size-1-i]);
    }
}
void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sort (int *values, int size){
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
            if (values[i] > values[j]){
                swap (&values[i], &values[j]);
            }
        }
    }
}
void desort (int *values, int size){
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
            if (values[i] < values[j]){
                swap (&values[i], &values[j]);
            }
        }
    }
}
void viewArray (int *a, int size){
    for (int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
