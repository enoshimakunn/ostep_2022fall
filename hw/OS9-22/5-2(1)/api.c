#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int x = 0;
    if (fork() == 0){
        printf("Child process: x = %d\n", x);
        x = 100;
        printf("Child process (altered): x = %d\n", x);
        exit(0);
    }
    else{
        printf("Parent process: x = %d\n", x);
        x = 500;
        printf("Parent process (altered): x = %d\n", x);
    }
    printf("%d\n", x);
}