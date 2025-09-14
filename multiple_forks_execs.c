#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void) {
	pid_t c1 = fork();

	if (c1 < 0) {
		perror("fork1 failed");
		exit(1);
	}
	if (c1 == 0) {
		execl("/bin/ls", "ls", (char *) NULL);
		perror("execl ls failed");
		exit(1);
	}

	pid_t c2 = fork();

	if (c2 < 0) {
                perror("fork2 failed");
                exit(1);
        }

        if (c2 == 0) {
		execl("/bin/date", "date", (char *) NULL);
		perror("execl date failed");
		exit(1);
	}

        waitpid(c1, NULL, 0);
	waitpid(c2, NULL, 0);

	printf("Parent process done");
	return 0;
}
