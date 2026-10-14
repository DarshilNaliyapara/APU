#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigalarm(int sig){
	printf("Hello here i am alarm handler \n");
}

int main(){
	signal(SIGALRM, sigalarm);

	printf("pid %d, waiting for SIGALRM...\n", getpid());
	alarm(3);
	pause();    /* sleep until signal arrive */

	printf("done\n");
	return 0;
}
	
