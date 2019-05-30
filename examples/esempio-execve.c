#include <stdio.h>
#include <unistd.h>
int main(){
    char *argv[2] = {"env2", NULL};
    char *envp[3] = {"var1=valore1", "var2=valore2", NULL};
    execve("./env2", argv, envp);
    perror("execve fallita");
    return 1;
}