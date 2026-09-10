#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char*argv[]){
    if (mkdir(argv[1], 0666) == 0){
        printf("Dir created!!!");
    }
    else{
        printf("Error While Creating Dir");
    }
}