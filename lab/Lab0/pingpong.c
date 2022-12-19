#include "types.h"
#include "stat.h"
#include "user.h"

int main(){
    int ptoc[2], ctop[2];   //Array that is to store file descriptors in 
    int pid = 0;
    char bufa[512], bufb[512];  //Content buffer

    pipe(ptoc); //Generating a pair of pipes
    pipe(ctop);
    if (fork() == 0){   //Create a child process
        close(ptoc[1]); //Close the writing end from parent to child...
        close(ctop[0]); //and the reading end from child to parent
        read(ptoc[0], bufb, 1); //Receive the signal from the parent...
        write(ctop[1], bufa, 1);    //and send out a signal
        close(ptoc[0]); //Close the remaining ends
        close(ctop[1]);
        pid = getpid();
        printf(2, "%d: received ping\n", pid);
    }
    else{
        close(ctop[0]); //Close the writing end from child to parent...
        close(ptoc[1]); //and the reading end from parent to child
        read(ctop[0], bufa, 1); //Receive the signal from the child...
        write(ptoc[1], bufb, 1);    //and send out a signal
        pid = getpid();
        printf(2, "%d: received pong\n", pid);
        close(ctop[0]);
        close(ptoc[1]);
    }
    exit();
}