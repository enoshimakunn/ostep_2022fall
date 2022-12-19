#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char* argv[]){
    int PAGESIZE = getpagesize();
    int NUMPAGES = atoi(argv[1]); //First argument stands for number of pages to touch...
    int trials = atoi(argv[2]); //and second number of trials. 
    struct timeval timer_start, timer_finish;
    int jump = PAGESIZE / sizeof(int);
    int *a = calloc(NUMPAGES, jump);

    gettimeofday(&timer_start, NULL);
    long start_time = timer_start.tv_sec * pow(10, 9) + timer_start.tv_usec * 1000;
    for (int i = 0; i < trials; i++){
        for(int j = 0; j < NUMPAGES * jump; j += jump){
            a[j]++;
        }
    }
    gettimeofday(&timer_finish, NULL);
    long finish_time = timer_finish.tv_sec * pow(10, 9) + timer_finish.tv_usec * 1000;
    float interval = finish_time - start_time;
    float avg = (interval) / (trials * NUMPAGES);
    //printf("Average time cost is: %f nanoseconds.\n", avg);
    free(a);

    FILE *fp = NULL;
    fp = fopen("out.txt", "a");
    fprintf(fp, "%d\t%f\n", NUMPAGES, avg);
}