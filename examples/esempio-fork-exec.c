#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    switch (pid){
        case -1:
            perror("fork() failed");
            return 1;
        case 0:
            printf("Esecuzione di ls...\n");
            execl("/bin/ls", "ls", "-l", NULL);
            perror("exec failed");
            return 1;
        default:
            //wait(NULL) significa che aspetta fin quando 
            //non cambia stato il processo figlio
            //precisamente in questo caso finche' non muore il figlio
            wait (NULL);
            printf("ls completed\n");
            return 0;
    }
}