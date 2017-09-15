#include <stdio.h>
#include <number_theory.h>

int main() {
	int factors[10];
	long triangular = 0L;
	long incr = 1L;
	int num_factor = -1;
	while (num_factor < 500) {
		triangular += incr++;
		factor(triangular, factors, 20);
		num_factor = 1;
		int i;
		for (i = 0; i < 10; i++) {
			num_factor *= factors[i] + 1;
		}
		printf("%ld has %d factors\n", triangular, num_factor);
	}
	printf("\n%ld is the first triangular number to have over 500 divisors.\n", triangular);
}