#include <stdio.h>
#include <number_theory.h>

int main() {
	long sum = 0L;
	long i;

	for (i = 0L; i < 2000000L; i++) {
		if (is_prime(i)) sum += i;
	}

	printf("The sum of all the primes below two million is %ld\n", sum);
}