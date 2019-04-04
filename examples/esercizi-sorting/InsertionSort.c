#include <stdio.h>
#define SIZE 5
void sort(int *a, int size);
void viewArray (int *a, int size);
void swap (int *a, int *b);
void insertInputArray (int *a, int size);

int main(){
    int a[SIZE];
    insertInputArray(a, SIZE);
    viewArray(a,SIZE);
    sort(a, SIZE);
    viewArray(a,SIZE);
    return 0;
}
void insertInputArray (int *a, int size){
    for (int i=0; i<SIZE; i++){
        printf("Inserisci %desimo numero: ", i+1);
        scanf("%d", &a[i]);
    }
}
void sort (int *a, int size){
    for (int i=0; i<SIZE; i++){
        for (int j=i+1; j<SIZE; j++){
            if (a[i] > a[j]){
                swap (&a[i], &a[j]);
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
void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}