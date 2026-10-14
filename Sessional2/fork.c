#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	int status;
	pid_t pid;
	pid = fork();
	if (pid < 0){
		printf("Fork Failed");
		exit(1);
	}
	else if(pid == 0){
		printf("I am Child my pid = %d, my parent pid = %d\n", getpid(), getppid());
		exit(10);
	}
	else{
		printf("I am Parent waiting for child to finish\n");
		 pid_t result = waitpid(pid,&status,0);
		
        if (result == pid) {
            if (WIFEXITED(status)) {
                printf("Child exited with status: %d\n", WEXITSTATUS(status));
            }
        } else {
            perror("waitpid failed");
        }
	}
	return 0;
}
