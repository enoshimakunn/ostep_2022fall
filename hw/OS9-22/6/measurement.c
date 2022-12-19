#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

int main(){
    int i, delta_sec, delta_usec, span_sec = 0, span_usec = 0;
    long max_iter = 10000000;
    float avg_calling_time_sec, avg_calling_time_usec;
    struct timeval tv_start, tv_end;

    for (i = 0; i < max_iter; i++){
        gettimeofday(&tv_start, NULL);
        read(1, NULL, 0);
        gettimeofday(&tv_end, NULL);
        span_usec += (tv_end.tv_usec - tv_start.tv_usec + (tv_end.tv_sec - tv_start.tv_sec) * 1000000);
    }

    avg_calling_time_sec = span_sec / (float) max_iter;
    avg_calling_time_usec = span_usec / (float) max_iter;
    printf("Average calling time is: %f\n", avg_calling_time_usec);
}