#include <stdio.h>
/*
    l'idea e' di contare quanti accapo  vengono inseriti
*/
int main (){
    int c = getchar();
    double nc = 0;  //number of char
    while (c!=EOF){
       if (c=='\n'){
            ++nc;
        }
        c = getchar();
    }
    printf("\nNumber of lines: %.0f\n", nc);
    return 0;
}
