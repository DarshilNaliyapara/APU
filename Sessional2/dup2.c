#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	int fd;
	fd = open("test.txt", O_WRONLY |O_APPEND | O_CREAT, 0777);
	if (fd >= 0){
		printf("Old FD = %d\n",fd);
		fd = dup2(fd,1);
		printf("this is from dup2");
	}
	else{
		printf("Error while open file\n");
		exit(1);
	}
}
