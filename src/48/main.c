#include <stdio.h>

int main() {
	long ret = 0L;
	int i,j;
	for (i = 1; i <= 1000; i++) {
		long product = 1L;
		for (j = 0; j < i; j++) {
			product = (product * i) % 10000000000L;
		}
		ret = (ret + product) % 10000000000L;
	}
	printf("The first 10 digits of sum of the first 1000 self powers are %ld\n", ret);
}