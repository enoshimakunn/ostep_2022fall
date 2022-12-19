#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

int main(){
    int p[2];
    char* const env[] = {"a = 1", "b = 2", NULL}; 
    if (fork() == 0){
        execvpe("/bin/ls", NULL, env);
    }
}