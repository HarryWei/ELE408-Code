#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	int a = 0;
	int *aPtr = NULL;

	a = 7;
	aPtr = &a;

	printf("Value of a: %d\n", a);
	printf("Addr of a: %p\n", &a);
	printf("value of aPtr: %p\n", aPtr);
	printf("Addr of aPtr: %p\n", &aPtr);

	return 0;
}
