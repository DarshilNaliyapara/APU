#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
	struct flock lock;
	int fd = open("test.txt",O_RDWR | O_CREAT, 0666);
	if (fd == -1){
		perror("open");
		exit(1);
	}
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	
	printf("Locking file");
		
	if (fcntl(fd,F_SETLKW, &lock) == -1){
		perror("fcntl F_SETLKW");
		exit(1);
	}

	printf("press any key to remove lock");
	getchar();
	
	lock.l_type = F_UNLCK;
	
        if (fcntl(fd,F_SETLKW, &lock) == -1){
                perror("fcntl F_SETLKW");
                exit(1);
        }
	
	printf("lock released!!");
	
	close(fd);
	return 0;
}
