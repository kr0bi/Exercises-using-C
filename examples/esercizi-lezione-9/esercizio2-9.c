#include <stdio.h>
#define SIZE 5
void reverse(int *a, int size);
void swap(int *a, int *b);
int main(){
    int a[SIZE];
    for (int i=0; i<SIZE; i++){
        printf("Inserisci %desimo numero: ", i+1);
        scanf("%d", &a[i]);
    }
    reverse(&a[0], SIZE);
    for (int i=0; i<SIZE; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void reverse (int *a, int size){
    int *primoPuntatore = &a[0];
    int *secondoPuntatore = &a[SIZE-1];
    for (int i=0; i<SIZE/2; i++){
        swap(primoPuntatore, secondoPuntatore);
        ++primoPuntatore;
        --secondoPuntatore;
    }
}
void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}