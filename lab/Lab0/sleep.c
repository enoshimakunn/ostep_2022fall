#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){
    int arg;

    if (argc < 2){
        printf(2, "sleep ERROR: too few arguments.\n");
    }
    else{
        arg = atoi(*argv);  //Morph argv into integer type using function atoi
        printf(2, "(Nothing happens for a little while...)\n");
        sleep(arg);
    }
    exit();
}
