#include <stdio.h>
#include <string.h>
//argv = punta ad un array di puntatori a carattere
//l'ultimo elemento (argv[argc] e' sempre NULL)
int main (int argc, char **argv){
    int somma = 0;
    //se il numero di parametri presenti e' maggiore/uguale a 2
    // e se il secondo parametro e' -s, il programma eseguira'
    // la somma tra due numeri
    if (argc >=2 && strcmp(argv[1], "-s") == 0){
        somma = 1;
    }
    int x = 0, y = 0;
    printf ("Inserire due numeri: ");
    int n = scanf("%d %d", &x, &y);
    if (somma){
        printf ("%d + %d = %d\n", x, y, x+y);
    } else {
        printf ("%d * %d = %d\n", x, y, x*y);
    }
}