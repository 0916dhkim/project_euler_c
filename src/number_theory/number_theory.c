#include <number_theory.h>

long gcd(long a, long b) {
	long less = 0;
	long gcd = 0;

	// Determine which number is greater.
	if (a < b) {
		less = a;
	} else {
		less = b;
	}

	// Invert the smaller number if it is negative.
	if (less < 0) {
		less = -less;
	}

	for (gcd = less; gcd != 1L; gcd--) {
		// Return if gcd is a common divisor.
		if (a % gcd == 0L && b % gcd == 0L) {
			return gcd;
		}
	}

	// GCD is 1.
	return gcd;
}

long lcm(long a, long b) {
	// LCM = a * b / GCD
	return a * b / gcd(a, b);
}

long greatest_prime_factor(long num) {
	long i;

	// The greatest prime factor of a number cannot be
	// greater than the square root of the number.
	for (i = 2L; i * i <= num; i++) {
		if (num % i == 0L) {
			// If i is a factor of num,
			return greatest_prime_factor(num/i);
		}
	}
	return num;
}

bool is_prime(long num) {
	if (num == 1L) {
		// 1 is not a prime number.
		return false;
	} else if (num == greatest_prime_factor(num)) {
		// If the greatest prime factor of a number is the number itself,
		// the number is a prime number.
		return true;
	} else {
		return false;
	}
}

void factor(long num, int *output_arr, int num_prime) {
	static long primes[1000000];
	static int known = -1;

	// Use memoization for the first 1 million prime numbers.
	int i;
	for (i = 0; i < num_prime && i < 1000000; i++) {
		if (i > known) {
			// If i'th prime number is not known,
			// find it.
			if (i == 0) {
				primes[0] = 2L;
				known = 0;
			} else {
				int j = known;
				while (j != i) {
					long k = primes[j] + 1L;
					while (!is_prime(k)) k++;
					j++;
					primes[j] = k;
				}
			}
		}

		output_arr[i] = 0;
		while (num % primes[i] == 0L) {
			output_arr[i]++;
			num /= primes[i];
		}
	}

	// After 1 millionth prime number,
	// do not use memoization.
	if (num_prime >= 1000000) {
		long prime = primes[1000000 - 1];
		for (i = 1000000; i < num_prime; i++) {
			prime++;
			while (!is_prime(prime)) prime++;
			output_arr[i] = 0;
			while (num % prime == 0L) {
				output_arr[i]++;
				num /= prime;
			}
		}
	}
}