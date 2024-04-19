#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char **argv) {
	int pid;
	int mydata = 1;

	pid = fork();
	if (pid != 0) {
		mydata = 2;
		printf("Parent: PID %d, PPID %d\n", getpid(), getppid());
		printf("My child's pid is %d\n", pid);
		printf("Mydata in parent is %d, addr is %p\n", mydata, &mydata);
	} else {
		printf("Child: PID %d, PPID %d\n", getpid(), getppid());
		mydata = 3;
		printf("Mydata in child is %d, addr is %p\n", mydata, &mydata);
		exit(EXIT_FAILURE);
	}

	printf("PID %d terminates.\n", getpid());
	exit(EXIT_SUCCESS);

	return 0;
}

