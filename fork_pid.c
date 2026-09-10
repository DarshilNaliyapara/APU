#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    pid_t pid = fork();
    if (pid < 0){
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
      printf("Hello from Child! PID: %d\n", getpid());
    } else {
      printf("Hello from Parent! Child PID: %d // Parent PID: %d\n", pid, getppid());
    }
    return 0;
}