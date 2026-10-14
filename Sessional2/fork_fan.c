#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	printf("I am Parent my pid is %d\n",getpid());
	for (int i = 0; i < 5; i++){
		pid = fork();
		if (pid == 0){
			printf("I am child process #%d, my pid is: %d, my parent is: %d\n",i+1,getpid(),getppid());
			exit(0);
		}
	}
	for(int i = 0; i<5; i++){
		wait(NULL);
	}
}
