#include <stdio.h>
#include <unistd.h>

int main(){
    char buf;
    while(1){
        int fd = read(0,&buf,1);

        if(fd == 0){
            printf("Thank you for using this!!!");
            break;
        }

        write(1,&buf,1);
    }
return 0;
}
