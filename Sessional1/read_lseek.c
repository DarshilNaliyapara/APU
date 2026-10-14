#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    char buff;
    int fd = open("test.txt", O_RDWR);
    int n = read(fd, &buff, sizeof(buff));
    lseek(fd, 3, SEEK_SET);
    write(fd, "Hello World", 12);
    return 0;
}