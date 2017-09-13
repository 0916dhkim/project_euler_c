#include <stdio.h>
#include <number_theory.h>

int main() {
	long sum = 0L;
	int i;
	int prime_sieve[2000000];

	for (i = 0; i < 2000000; i++) {
		prime_sieve[i] = 1;
	}

	for (i = 1; i < 2000000; i++) {
		if (prime_sieve[i]) {
			if (is_prime(i)) {
				int j;
				for (j = i * 2; j < 2000000; j += i) {
					prime_sieve[j] = 0;
				}
				sum += i;
			}
		}
	}

	printf("The sum of all the primes below two million is %ld\n", sum);
}