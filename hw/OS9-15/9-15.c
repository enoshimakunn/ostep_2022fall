#include<stdio.h>

int main(){
    int i = 1, j = 2, k;
    int num = 0;
    k = i + j;
    k = i - j;
    k = i * j;
    k = j / i;
    if (k == 2){
        k = j / i;
    }
    else{
        for (k; k!=2; k++){
            num++;
        }
    }
}