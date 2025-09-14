#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
        pid_t pid = fork();

	if (pid < 0) {
		perror("fork failed");
		exit(1);
	}

	if (pid == 0) {
		execl("/bin/ls", "ls", (char *)NULL);
		perror("execl failed");
		exit(1);
	} else {
		wait(NULL);
		printf("Parent process done\n");
	}

	return 0;
}

