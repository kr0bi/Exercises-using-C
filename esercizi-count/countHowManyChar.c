#include <stdio.h>
/*
    l'idea e' di contare quanti char vengono inseriti
*/
int main (){
    int c = getchar();
    double nc = 0;  //number of char
    while (c!=EOF){
        ++nc;
        c = getchar();
    }
    printf("\nNumber of chars: %.0f\n", nc);
    return 0;
}
