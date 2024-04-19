#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int global = 10;

void *func(void *id) {
	int *myid = (int *) id;

	int test = 0;

	printf("This is thread %d\n", *myid);
	printf("Global is %d, addr. %p\n", global, &global);
	printf("test is %d, addr. %p\n", test, &test);
	pthread_exit(NULL);
}

int main (int argc, char **argv) {
	pthread_t thread[10];
	int ret;
	int i;
	int index[10];

	for (i = 0; i < 10; i++) {
		index[i] = i;
		ret = pthread_create(thread+i, NULL, func, &(index[i]));
		if (ret != 0) fprintf(stderr, "Thread create error!\n");
	}

	for (i = 0; i < 10; i++) {
		pthread_join(thread[i], NULL);
	}

	printf("Main thread finished!\n");

	return 0;
}
