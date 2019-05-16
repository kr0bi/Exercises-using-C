#include <stdio.h>
#include <string.h>
/*
    Restituisce il puntatore alla prima occorrenza
    del carattere c
    Se non viene trovato ritorna un puntatore null
*/
char *strchar(char *str, char c);
/*
    Restituisce il puntatore alla prima occorrenza
    della stringa pattern
    Se non viene trovato ritorna un puntatore null
*/
char *strstring(char *str, char *pattern);

int main(){
    char c = 'c';
    char str0[] = "ciao sono daniele";
    char str1[] = "123456789c";
    char str2[] = "sono daniele ciao";
    char str3[] = "";
    /*
    printf("%s & %c => %p %p\n", str0, c, strchar(str0, c), strchr(str0, 'i'));
    printf("%s & %c => %s\n", str1, c, strchar(str1, c));
    printf("%s & %c => %s\n", str2, c, strchar(str2, c));
    printf("%s & %c => %s\n", str3, c, strchar(str3, c));
    */
    //printf("%s && %s => %s\n", "ciaosonoDaniele", "sono", strstr("ciaosonoDaniele", "sono"));
    printf("%s && %s => %s\n", "ciaosonoDaniele", "Dan", strstring("ciaosonoDaniele", "Dan"));

}

char *strchar (char *str, char c){
    for (char *i=&str[0]; *i; ++i){
        if (c == *i){
            return i;
        }
    }
    return NULL;
}

char *strstring (char *str, char *pattern){
    /*
        l'idea e' di verificare se e' presente il primo carattere del pattern
        all'interno della stringa, se e' presente, verificare che sia presente il secondo carattere
        fino a che non si completa tutto il pattern
    */
   char *primaIstanza = NULL;
   if (strchar(str, pattern[0])==NULL){
       return primaIstanza;
   } else {
       //puntatore che contiene la prima istanza del
       // pattern all'interno della stringa
       primaIstanza = strchar(str, pattern[0]);
   }
   char *puntatorePrecedente = primaIstanza;
   char *puntatoreSuccessivo = NULL;
   char *stringaDaModificare = primaIstanza;
   //itero tutta la stringa pattern all'interno di str
   for (int i =1; pattern[i]!='\0'; ++i){
       puntatoreSuccessivo = strchar(stringaDaModificare, pattern[i]);

       /*printf("primaIstanza: %s\n", primaIstanza);
       printf("primoPuntatore: %s\n", puntatorePrecedente);
       printf("secondoPuntatore: %s\n", puntatoreSuccessivo);
       printf("%p --- %p\n", puntatorePrecedente, puntatoreSuccessivo);
       printf ("%ld\n", puntatoreSuccessivo-puntatorePrecedente);
       */
       if (puntatoreSuccessivo-puntatorePrecedente==1){
           puntatorePrecedente = puntatoreSuccessivo;
           ++stringaDaModificare;
       } else {
           primaIstanza = NULL;
           break;
       }
   }
   return primaIstanza;
   
}