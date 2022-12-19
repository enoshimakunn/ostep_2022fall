This repository contains the answer for Q2 and Q4 in chapter39, OSTEP. 

myls.c is a program that simulates ls in Linux operating system which lists all the 
regular files and secondary directories in the given path. The program uses getopt() 
to acquire the path arguement and scans the secondary entries with opendir() and readdir(), 
the former returning the DIR pointer of the given path and the latter returning a dirent pointer 
of secondary entries one at a time. We then use those dirent pointers to acquire the name of 
the file or the directory using variable d_name, and then constructs the path to the secondary 
entries which are our main focus. stat() is then used to acquire all the information of the 
files and directories. 

Run myls.c with commands below:
./myls                                  will print out files under the current working directory.
./myls -l yourpath                      will print out files under the given directory. 

search.c is a program that lists the files recursively under the given root directory. 
It's also equipped with a -s flag that activates search mode, which is an imitation of find 
in Linux. 

Run search.c with commands below:
./search -p yourpath                    will print out files recursively under the given rootpath.
./search -p yourpath -s filename        will find all files under the given rootpath with the filename given. 