#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t c1 = fork();

	if (c1 < 0) {
		perror("fork failed");
		exit(1);
	}
	if (c1 == 0) {
		execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
		perror("execl echo failed");
		exit(1);
	}
        else {
           	wait(NULL);
        	printf("Parent process done");
	}
	
	return 0;
}
