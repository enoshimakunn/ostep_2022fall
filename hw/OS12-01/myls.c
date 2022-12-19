#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>  
#include <dirent.h>
#include <unistd.h> 
#include <string.h>
#include <stdbool.h>

int main(int argc, char *acgv[]){
    DIR* dirptr;
    int opt;
    char* path;
    char* path_f = (char*)malloc(100);
    bool l_flag = false;
    struct stat st;
    struct stat st_f;
    struct dirent *dptr;
    
    //printf("check\n");
    while((opt = getopt(argc, acgv, "l:")) != -1){
        switch(opt){
            case 'l': 
                path = optarg;
                l_flag = true; 
                break;
            
            case '?':
                if (optopt == 'l') l_flag = true;
                path = ".";
                break;

            default:
                break;
        }
    }

    if(argc == 1){
        path = ".";
    }
    else if (argc == 2 && l_flag == false) path = acgv[1];


    stat(path, &st);

    dirptr = opendir(path);
    dptr = readdir(dirptr);

    //printf("check\n");
    if(l_flag == true){
        printf("Name\t");
        printf("UID\t");
        printf("GID\t");
        printf("Last Modified\t\t");
        printf("Size\t");
        printf("\n");
    }

    while(dptr != NULL){
        

        printf("%s\t", dptr->d_name);
        if(l_flag == true){
            //printf("%s\t", path);
            //printf("%s\n", path_f);
            strcpy(path_f, path);
            strcat(path_f, "/");
            strcat(path_f, dptr->d_name);
            //printf("%s\t", path_f);
            stat(path_f, &st_f);
            printf("%d\t", st_f.st_uid);
            printf("%d\t", st_f.st_gid);
            printf("%lld.%.9ld\t", (long long)st_f.st_mtim.tv_sec, st_f.st_mtim.tv_nsec);
            printf("%ld\t", st_f.st_size);
            printf("\n");
            //print_file(st_f);
        }
        dptr = readdir(dirptr);
        printf("\n");
    }
}