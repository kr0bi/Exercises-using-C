#include <stdio.h>
int main (){
    int c = getchar();
    /*
        EOF vale -1
    */
    while (c!=EOF){
        putchar(c);
        c = getchar();
    }
    
    return 0;
}