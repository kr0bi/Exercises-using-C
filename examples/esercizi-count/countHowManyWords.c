#include <stdio.h>
/*
    word: sequence of characters that does not contain
        a blank, tab or newline
*/
int main(){
    int c = getchar();
    double nc = 0;  //number of char
    int isPrecedentCharALettera = 0;  
    
    while (c!=EOF){
       if ((c!='\n' && c!='\t' && c!=' ')){
            isPrecedentCharALettera = 1;
        }
        if (isPrecedentCharALettera && (c=='\n' || c=='\t' || c==' ')){
            ++nc;
            isPrecedentCharALettera = 0;
        }
        c = getchar();
    }
    if (isPrecedentCharALettera){
        ++nc;
    }
    printf("\nNumber of words: %.0f\n", nc);
    return 0;
}