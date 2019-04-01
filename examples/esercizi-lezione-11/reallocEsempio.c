#include <stdio.h>
#include <stdlib.h>

void reverse (int *array, int size);
void viewArray(int *a, int size);
void swap (int *x, int *y);
int main (){
    int size = 10;
    int *array = malloc(size*sizeof(int));
    int read = 0;
    while (scanf("%d", &array[read]) == 1){
        if (++read == size){
            size *= 2;
            array = realloc(array, size * sizeof(int));
        }
    }
    reverse(array, read);
    viewArray(array, read);
    free(array);
    return 0;
}

void reverse (int *values, int size){
    for (int i=0; i<size/2; i++){
        swap(&values[i], &values[size-1-i]);
    }
}
void viewArray (int *a, int size){
    for (int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}