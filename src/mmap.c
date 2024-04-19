#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char **argv) {
	int ret = 0;
	int i = 0;
	int fd = open("./file.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd < 0) {
		fprintf(stderr, "Open error!\n");
		return -1;
	}

	//int flen = strlen("Hello World\n") + 1;
	struct stat statbuf;
	ret = fstat(fd, &statbuf);
	if (ret < 0) {
		fprintf(stderr, "fstat error!\n");
		return -1;
	}
	int flen = statbuf.st_size;
	char *map = mmap(NULL, flen, PROT_READ, MAP_SHARED, fd, 0);
	if (map == MAP_FAILED) {
		ret = -1;
		fprintf(stderr, "Mmap error!\n");
		goto out;
	}
	for (i = 0; i < flen; i++) {
		printf("%c", map[i]);
	}

	if (munmap(map, flen) == -1) {
		fprintf(stderr, "Munmap error!\n");
		ret = -2;
		goto out;
	}

out:
	close(fd);
	return ret;
}
