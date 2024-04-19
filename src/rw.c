#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	int fd = open("./file.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	
	char *buf = "Hello World\n";
	int offset = 0;
	int size = pwrite(fd, buf, strlen(buf) + 1, offset);
	if (size != (strlen(buf) + 1)) {
		fprintf(stderr, "Pwrite error!\n");
		return -1;
	}

	char rbuf[1024];
	memset(rbuf, '\0', 1024);
	int rsize = pread(fd, rbuf, size, offset);
	if (rsize != size) {
		fprintf(stderr, "Pread error!\n");
		return -1;
	}
	printf("Read contents: %s", rbuf);

	close(fd);
	return 0;
}
