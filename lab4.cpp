#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() 
{
	int a;	
	printf("program just started...\nparent pid: %d, ppid: %d\n\n", getpid(), getppid());
	printf("initialized fork()\n");	
	pid_t pid = fork();
	if (pid == 0) {
		printf("pid = 0 - daughter program launching\n");
		execl("./lab4.1", "-l", "-d", NULL);
	}
	else if (pid > 0) {
		while (waitpid(pid, &a, WNOHANG) == 0) {
			printf("wait...\n");
			sleep(1);
		}
		printf("code zaversheniya dochernego processa: %i\n", a);
		fflush(stdout);
	}
	else {
		perror("fork call error");
		fflush(stdout);
	}
	printf("program just ended...\n");
	fflush(stdout);	
	return 0;
}
