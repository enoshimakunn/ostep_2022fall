#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include <sys/wait.h>

int main(){
    int childpid;
    int i;
    if (fork() == 0){
        i = wait(NULL);
        printf("%d\n", i);
        printf("Hit you with that\n");
        exit(0);
    }
    else{
        printf("Duh-Duh-Duh-Dum\n");
    }
}