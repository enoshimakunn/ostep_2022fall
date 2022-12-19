#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include <sys/wait.h>

int main(){
    int childpid;
    if (fork() == 0){
        printf("Hit you with that\n");
        exit(0);
    }
    else{
        waitpid(-1, NULL, 0);
        printf("Duh-Duh-Duh-Dum\n");
    }
}