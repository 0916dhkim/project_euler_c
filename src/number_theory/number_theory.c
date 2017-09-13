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