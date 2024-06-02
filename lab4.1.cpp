#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[])
{
	printf("second program started...\n");
	if (!strcmp(argv[0], "-l")) {
		printf("The -l flag was delivered!\n");
	}
	if (!strcmp(argv[1], "-d")) {
		printf("The -d flag was delivered!\n");
	}		
		
	int i;
	for (i = 0; i < 10; i++) {
		printf("daughter iteration %i: pid %d, ppid %d \n", i, getpid(), getppid());
		sleep(1);
	}
	return 0;
	printf("second program ended...\n");
	exit(0);
}

