#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	for (int i = 1; i < 6; i++){
		pid = fork();
		if (pid == 0){
			printf("I am child process #%d, my pid is: %d, parent pid = %d\n",i,getpid(),getppid());
		}
		else {
			wait(NULL);
			break;
		}
	}
}
