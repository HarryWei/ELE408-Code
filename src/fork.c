#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char **argv) {
	int pid;

	printf("Parent: PID %d, PPID %d\n", getpid(), getppid());
	pid = fork();
	if (pid != 0) {
		printf("Parent: PID %d, PPID %d\n", getpid(), getppid());
		printf("My child's pid is %d\n", pid);
	} else {
		printf("Child: PID %d, PPID %d\n", getpid(), getppid());
		exit(EXIT_FAILURE);
	}

	printf("PID %d terminates.\n", getpid());
	exit(EXIT_SUCCESS);

	return 0;
}

