#include <stdio.h>
#include <unistd.h>

int main(){
    uid_t uid = getuid();
    gid_t gid = getgid();
    printf("UID=%d, GID=%d\n", uid, gid);
    return 0;
}