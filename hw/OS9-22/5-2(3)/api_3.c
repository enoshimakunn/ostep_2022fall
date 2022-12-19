#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

int main(){
    int p[2];
    char buf[512];
    pipe(p);
    if (fork() == 0){
        printf("hello\n");
        write(p[1], buf, 1);
    }
    else{
        read(p[0], buf, 1);
        printf("goodbye\n");
    }
}