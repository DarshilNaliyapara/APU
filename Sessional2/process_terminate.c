#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status;
	int num = 2;
	if(num == 0){
		pid = fork();
		if (pid == 0){
			printf("Normal Termination");
			exit(0);
		}
		else if(pid > 0){
			wait(&status);
		}
	}
	else if(num == 1){
		pid = fork();
		if (pid == 0){
			printf("Abnormal Termination");
			exit(1);
		}
		else if(pid > 0){
                        wait(&status);
                }
	}
	else{
		pid = fork();
		if (pid == 0){
			printf("Signal Termination");
			kill(getpid(),SIGKILL);
		}
		else if(pid > 0){
                        wait(&status);
                }

	}
	if (WIFEXITED(status)) {
		printf("Child exited normally with status: %d\n", WEXITSTATUS(status));
	}
	else if (WIFSIGNALED(status)) {
		printf("Child terminated by signal: %d\n", WTERMSIG(status));
	}
	else {
		printf("Child terminated abnormally\n");
	}
}

