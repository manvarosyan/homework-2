#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t c1 = fork();
    if (c1 < 0) {
	    perror("fork failed");
	    return 1;
    }

    if (c1 == 0) {
        execl("/usr/bin/grep", "grep", "main", "test.txt", (char *)NULL);
        perror("execl grep"); 
	exit(1);
    } else {
        wait(NULL);
        printf("Parent process completed\n");
    }
    return 0;
}

