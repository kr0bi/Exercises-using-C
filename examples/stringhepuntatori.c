#include <stdio.h>
int strlength(char *s);
int strncompare(char *c1, char *c2, unsigned len);
int main(){
    char msg[] = "Hello world!";
    printf("Stringa: %s \n", msg);
    printf("Caratteri: ");
    for (char *p=msg; *p; ++p){
        printf("'%c' ", *p);
    }
    printf("\n");
    printf("La lunghezza della tua stringa e' %d\n", strlength(msg));
    char msg1[] = "Hello world!";
    char msg2[] = "Hello world!";
    char msg3[] = "xD";

    printf("msg1&msg2: %d, msg1&msg3: %d\n", strncompare(msg1, msg2, strlength(msg1)), strncompare(msg1, msg3, strlength(msg2)));
    return 0;
}

int strlength (char *s){
    int strlen = 0;
    for (char *p=s; *p; ++p){
        ++strlen;
    }
    return strlen;
}
int strncompare (char *c1, char *c2, unsigned len){
    int result = 0;
    int n=0;
    while (len>n){
        if (c1[n]!=c2[n]){
            result = -1;
        }
        ++n;
    }
    return result;                                                                                            
}