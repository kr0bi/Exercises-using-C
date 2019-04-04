#include <stdio.h>
#include <math.h>
#define SIZE 5

void MergeSort (int *a, int size, int p, int q);
void Merge (int *a, int size, int p, int q, int r);
void insertInputArray (int *a, int size);
void viewArray (int *a, int size);

int main (){
    int a[SIZE];
    insertInputArray(a, SIZE);
    viewArray(a, SIZE);
    MergeSort(a, SIZE, 0, SIZE-1);
    viewArray(a, SIZE);
    return 0;
}

void MergeSort (int *a, int size, int p, int q){
    if (p < q){
        int r = (int)floor((double)(p+q)/2.0);
        MergeSort (a, size, p, r);
        MergeSort (a, size, r+1, q);
        Merge (&a[0], size, p, q, r);
    }
}

void Merge (int *a, int size, int p, int q, int r){
    int b[size];
    int i = p;
    int j = r+1;
    for (int k=p; k<=q;k++){
        if (i<=r && j<=q){
            if (a[i]<=a[j]){
                b[k] = a[i];
                ++i;
            } else if (a[i]>a[j]){
                b[k] = a[j];
                ++j;
            }
        } else if (i<=r){
            b[k]=a[i];
            ++i;
        } else if (j<=q){
            b[k]=a[j];
            ++j;
        }
    }
    for (int k=p; k<=q; k++){
        a[k]=b[k];
    }
}
void insertInputArray (int *a, int size){
    for (int i=0; i<SIZE; i++){
        printf("Inserisci %desimo numero: ", i+1);
        scanf("%d", &a[i]);
    }
}
void viewArray (int *a, int size){
    for (int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}