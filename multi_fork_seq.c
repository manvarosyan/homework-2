#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t p1 = fork();
	if (p1 < 0) {
			perror("fork1");
			exit(1);
		    }
         pid_t p2 = fork();
	 if (p2 < 0) {
		         perror("fork2");
		         exit(1);
                      }
         pid_t p3 = fork();
	 if (p3 < 0) {
		         perror("fork3");
	         	 exit(1);
	              }
          printf("PID=%ld PPID=%ld | p1=%ld p2=%ld p3=%ld\n",
           (long)getpid(), (long)getppid(), (long)p1, (long)p2, (long)p3);

	  while (wait(NULL) > 0) {}
	  return 0;
}
