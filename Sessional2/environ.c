#include <stdio.h>
#include <stdlib.h>

extern char **environ;
int main(int argc, char *argv[])
{
	char **ptr;
	int i;
	printf("\n Command line arguments \n");
	for(i=1;((i<argc) || (argv[i]!=NULL));i++)
	{
		printf("%s=%s\n",argv[i], getenv(argv[i]));
	}
	
	for (ptr = environ; *ptr != 0; ptr++){
		printf("%s\n",*ptr);
	}
	printf("\n Usage of getenv function ");
	printf("\n HOME=%s ",getenv("HOME"));
	
}
