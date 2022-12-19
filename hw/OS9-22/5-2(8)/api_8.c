#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include <sys/wait.h>

int main(){
    int p[2];
    char buf[512];
    pipe(p);
    if (fork() == 0){
        dup2(p[1], STDOUT_FILENO);
        write(STDOUT_FILENO, "God bless the king.\n", 21);  
    }
    else{
        if (fork() == 0){
            close(p[1]);
            dup2(p[0], STDIN_FILENO);
            read(STDIN_FILENO, buf, 21);
            printf("Child2 receive signal: %s\n", buf);
        }
        else{
            close(p[0]);
            close(p[1]);
        }
    }
}