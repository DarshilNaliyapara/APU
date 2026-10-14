#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	for (int i =0; i< 2; i++){
		pid = fork();
		if (pid == 0){
			char *argv1[] = {i == 0? "ls": "date", i == 0? "-l": NULL, NULL};
			printf("Print %s child %d\n",i == 0? "ls": "date", i);
			execvp(i == 0? "ls": "date", argv1);
			perror("exec");
			exit(1);
		}
		else if (pid > 0){
			wait(NULL);
		}
	}
}
