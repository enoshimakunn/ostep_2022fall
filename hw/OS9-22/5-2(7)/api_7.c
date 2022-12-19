#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include <sys/wait.h>

int main(){
    if (fork() == 0){
        close(STDOUT_FILENO);
        printf("3, 2, 1, let's jam!!\n");
        exit(0);
    }
    else{
        printf("Parent process going through...\n");
    }
}