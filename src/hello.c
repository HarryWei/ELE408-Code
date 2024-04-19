#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv) {
	//printf("Hello ELE408.\n");
	char a  = 24;
	int i = 0;

	for (i = 0; i < sizeof(a) * 8; i++) {
		printf("%d", (a & 0x80) >> 7);
		a = a << 1;
	}

	printf("\n");

	uint64_t x=10, y=10;

	printf("x<<y is: %lu\n", x<<y);
	printf("x>>1 is: %lu\n", x>>1);

	printf("\n");
	return 0;
}
