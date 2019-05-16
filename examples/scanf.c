#include <stdio.h>
int main(){
    int x = 0;
    printf("Inserisci un numero intero: ");
    //prende in input un indirizzo di memoria
    scanf("%d", &x);
    printf("Il doppio di %d e' %d\n", x, x*2);
    return 0;
}