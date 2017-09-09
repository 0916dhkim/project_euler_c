#include <stdio.h>

long greatest_prime_factor(long num) {
	long divisor = 2L;

	for(; divisor * divisor <= num ; divisor++) {
		// If num can be factored by divisor,
		// the greatest prime factor of num is
		// the greatest prime factor of num/divisor.
		if (num % divisor == 0L) {
			return greatest_prime_factor(num/divisor);
		}
	}

	// If num cannot be factored,
	// num is a prime number.
	return num;
}

int main() {
	printf("The greatest prime factor of 600851475143 is %ld\n" , greatest_prime_factor(600851475143L));
}
