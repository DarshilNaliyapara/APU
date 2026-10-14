#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    char ch;
    if (argc < 2){
        printf("Require files to copy.");
        return 1;
    }
    else if(!argv[2]){
      printf("Require destination to copy.");
      return 1;
    }
    int source = open(argv[1],O_RDONLY);
    int destination = open(argv[2], O_WRONLY | O_CREAT, 0644);
    while (read(source, &ch, 1) > 0) {
      write(destination,&ch,1);
    }
    return 0;
}