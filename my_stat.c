#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]){
    struct stat s;
    if (stat(argv[1],&s) == 0){
        printf("Byte size: %ld\n", s.st_size);
        printf("I-node number: %ld\n", s.st_ino);
        printf("Creation time: %s", ctime(&s.st_ctim.tv_sec));
    }
    return 0;
}