#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int cnt = 0;

void *func(void *id) {
	int *myid = (int *) id;

	int i = 0;

	printf("This is thread %d\n", *myid);

	for (i = 0; i < 100; i++) {
		cnt += 1;
	}
}

int main (int argc, char **argv) {
	pthread_t thread[2];
	int ret;
	int i;
	int index[2];

	for (i = 0; i < 2; i++) {
		index[i] = i;
		ret = pthread_create(thread+i, NULL, func, &(index[i]));
		if (ret != 0) fprintf(stderr, "Thread create error!\n");
	}

	for (i = 0; i < 2; i++) {
		pthread_join(thread[i], NULL);
	}

	printf("Main thread finished!\n");

	return 0;
}
