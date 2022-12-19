#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>  
#include <dirent.h>
#include <unistd.h> 
#include <string.h>
#include <stdbool.h>

extern bool s_flag = false;

void walk(char* path){
    DIR* dirptr;
    struct dirent *dptr;
    struct stat st;
    struct stat st_f;
    char* next_path = (char*)malloc(100);

    dirptr = opendir(path);
    dptr = readdir(dirptr);

    int i = 0;
    while(dptr != NULL){
        //printf("%d\n", i);
        //i++;
        if(strcmp(dptr->d_name, ".") && strcmp(dptr->d_name, "..")){
            //printf("%s\n", dptr->d_name);
            strcpy(next_path, path);
            strcat(next_path, "/");
            strcat(next_path, dptr->d_name);
            printf("%s\n", next_path);
            stat(next_path, &st_f);
            if(S_ISDIR(st_f.st_mode)) walk(next_path);
            else if(S_ISREG(st_f.st_mode)) printf("%s\n", next_path);
        }
        dptr = readdir(dirptr);
    }
}

void search(char* path, char* filename){
    DIR* dirptr;
    struct dirent *dptr;
    struct stat st;
    struct stat st_f;
    char* next_path = (char*)malloc(100);
    

    dirptr = opendir(path);
    dptr = readdir(dirptr);

    int i = 0;
    while(dptr != NULL){
        //printf("%d\n", i);
        //i++;
        if(strcmp(dptr->d_name, ".") && strcmp(dptr->d_name, "..")){
            //printf("%s\n", dptr->d_name);
            strcpy(next_path, path);
            strcat(next_path, "/");
            strcat(next_path, dptr->d_name);

            if(strcmp(dptr->d_name, filename) == 0){
                printf("%s\n", next_path);
                s_flag = true;
            }
            
            stat(next_path, &st_f);
            if(S_ISDIR(st_f.st_mode)) search(next_path, filename);
            //else if(S_ISREG(st_f.st_mode)) printf("%s\n", next_path);
        }
        dptr = readdir(dirptr);
    }
    //return s_flag;
}

int main(int argc, char* acgv[]){
    char* rootpath = (char*)malloc(100);
    char* filename = (char*)malloc(100);
    int opt;
    bool search_mode = false;
    bool search_flag = true;

    while ((opt = getopt(argc, acgv, "p:s:")) != -1) {
        switch(opt){
            case 's':
                search_mode = true;
                filename = optarg;
                break;

            case 'p':
                rootpath = optarg;
                break;

            case '?':
                if (optopt == 's') search_mode = true;
                rootpath = ".";
                break;

            default:
                fprintf(stderr, "Usage: %s [-s filename] [-p rootpath]\n", acgv[0]);
                exit(EXIT_FAILURE);
        }
    }
    /*
    printf("%s\n", rootpath);
    printf("%s\n", filename);
    printf("%d\n", search_mode);
    */


    /*
    if(argc == 1) getcwd(rootpath, 256);
    else if (argc == 2) rootpath = acgv[1];
    else printf("Too many arguments: expect 3 or less.\n");
    */
    if(search_mode == false) walk(rootpath);
    else{
        search(rootpath, filename);
        if(s_flag == false) printf("%s: No such file or directory\n", filename);
    }
}