#include <stdio.h>
int main (){
    int x = 0, y=0, z=0;
    printf("Inserisci tre numeri interi: ");
    scanf("%d%d%d", &x, &y, &z);
    printf("La somma di %d, %d e %d e': %d\n", x, y, z, x+y+z);
    return 0;
}