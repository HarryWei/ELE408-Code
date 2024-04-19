#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <assert.h>

int main(int argc, char **argv) {
	DIR *dp = opendir(".");
	assert(dp != NULL);
	struct dirent *d = NULL;
	while (NULL != (d = readdir(dp))) {
		printf("%d %s\n", (int) d->d_ino, d->d_name);
	}

	closedir(dp);
	return 0;
}
