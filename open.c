#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	char buf;
	int n = 0;
	if (argc>1){
		int fd = open(argv[1],O_RDONLY | O_DIRECTORY);
		if(fd >= 0){
			int dirfd =  openat(fd, "test.txt", O_RDONLY);
			if (dirfd>=0){
				while ((n = read(dirfd, &buf, 1)) > 0){
					write(1,&buf,1);
				}
			}
			else{
				printf("failed to open file");
				exit(1);
			}
		}
		else{
			printf("Failed to open dir");
			exit(1);
		}
	}
	else{
		printf("Please give directory name");
		exit(1);
	}
	return 0;	
}
