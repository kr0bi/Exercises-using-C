#include <stdio.h>
void swap (int *x, int *y);

int main(){
    int x = 42;
    int y = 33;
    swap(&x,&y);
    printf("%d, %d", x, y);
    return 0;
}
void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}