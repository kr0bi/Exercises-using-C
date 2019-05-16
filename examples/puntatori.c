#include <stdio.h>
int main(){
    int x = 42;
    int *p = &x;
    printf("%p <-- indirizzo \n%14d <-- valore all'indirizzo", p, *p);
    return 0;
}