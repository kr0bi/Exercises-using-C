#include <stdio.h>

int lg (int);
int power (int, int);

int main(){
    for (int i=1; i<1000; i=i+100){
        printf ("Il logaritmo di %d e' %d\n", i, lg(i));
    }
    return 0;
}

int power (int base, int exp){
    int p = 1;
    for (int i=0; i<exp; i++){
        p = p * base;
    }
    return p;
}

int lg (int n){
    int p=0;
    while (power(10, p)<=n){
        ++p;
    }
    return --p;
}