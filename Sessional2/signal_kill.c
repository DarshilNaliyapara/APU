#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void userhandler1(int sig){
	printf("Hello there i am user 1 handler \n");
}

void userhandler2(int sig){
	printf("Hello there i am user 2 handler \n");
}

int main(){
	signal(SIGUSR1, userhandler1);
	signal(SIGUSR2, userhandler2);
	printf("pid %d, waiting for kill...\n", getpid());
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);

	printf("done\n");
	return 0;
}
	
