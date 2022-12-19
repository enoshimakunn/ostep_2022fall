#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
    int i = 0;
    int fptr, num, size;
    char c[6];
    fptr = open("/Users/justin/Desktop/OS9-22/5-2(2)/2.txt", 10);
    if (fork() == 0){
        num = read(fptr, c, 1);
        printf("Child get: %s\n", c);
        size = write(fptr, "Hell ", 5);
    }
    else{
        num = read(fptr, c, 6);
        printf("Parent get: %s\n", c);
        size = write(fptr, "yeah!\n", 6);
    }
}