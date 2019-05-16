#include <stdio.h>

int main(){
    int array[] = {6,5,4,3,2,1};
    int dimensioneArray = 6;
    for (int i=0; i<dimensioneArray; i++){
        for (int j=i+1; j<dimensioneArray; j++){
            if (array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i=0; i<dimensioneArray; i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}