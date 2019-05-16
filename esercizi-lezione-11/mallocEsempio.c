#include <stdio.h>
//questa libreria serve per malloc
#include <stdlib.h>
/*
Esegue la somma dei numeri all'interno dell'array di grandezza size
*/
int somma (int *array, int size);
/*
    Questo programma esegue la somma di n numeri inseriti
*/
int main (){
    int n = 0;
    printf ("Quanti numeri verranno inseriti? ");
    scanf("%d", &n);
    if (n==0){
        return 0;
    }
    int *elementi = malloc (n*sizeof(int));
    printf("Inserire i numeri: ");
    for (int i=0; i<n; ++i){
        scanf("%d", elementi + i);
    }
    printf("La somma dei numeri inseriti e': %d\n", somma(elementi, n));
    return 0;
}

int somma (int *array, int size){
    int s = 0;
    for (int i=0; i<size; ++i){
        s+=array[i];
    }
    return s;
}