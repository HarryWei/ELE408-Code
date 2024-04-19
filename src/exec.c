#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int ret = 0;

	ret = execl("/usr/bin/ls", "-al", NULL);
	if (ret == -1) perror("execl");

	return 0;
}
