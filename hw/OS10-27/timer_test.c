#include<stdio.h>
#include<sys/time.h>

int main(){
    struct timeval timer;
    for(int i = 0; i < 10; i++){
        gettimeofday(&timer, NULL);
        printf("%ld\t%d\n", timer.tv_sec, timer.tv_usec);
    }
}