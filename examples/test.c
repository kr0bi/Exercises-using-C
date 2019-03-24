#include <stdio.h>

int main (){
    char stringa[] = "ciao";
    char *primoP = &stringa[1];
    char *secondoP = &stringa[0];
    printf ("%p, %p, %p, %p", &stringa[0], &stringa[1], &stringa[2], &stringa[3]); 
    return 0;
}