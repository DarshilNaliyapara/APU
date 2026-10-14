#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
		pid = fork();
		if (pid == 0){
			execl("/bin/ls","ls", "-l", NULL); // for execlp() you do not need /bin/ls "ls" is good.
			perror("execl");
			exit(1);
		}
		else if (pid > 0){
			wait(NULL);
		}
return 0;
}
