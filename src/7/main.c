#include <stdio.h>
#include <number_theory.h>

int main() {
	long i = 1L;
	int count = 0;

	while (count != 10001) {
		if (is_prime(i)) {
			printf("Prime number #%d : %ld\n", count, i);
			count++;
		}
		i++;
	}

	printf("The 10001st prime number is %ld\n", i);
}